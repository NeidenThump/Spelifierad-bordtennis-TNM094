function [sound_position_estimate] = positionCalc(Fs,speedofsound,micApos,micBpos,micCpos,soundMicA,soundMicB,soundMicC)

soundMicA = bandpass(soundMicA,[7500, 8500], Fs);
soundMicB = bandpass(soundMicB,[7500, 8500], Fs);
soundMicC = bandpass(soundMicC,[7500, 8500], Fs);

% Compute the cross-correlation between the two signals
[correlationAB, lagAB] = xcorr(soundMicA, soundMicB);
[correlationAC, lagAC] = xcorr(soundMicA, soundMicC);
%[correlationBC, lagBC] = xcorr(soundMicB, soundMicC);

% Find the index of the maximum correlation
[maxCorr1, maxIndex1] = max(abs(correlationAB));
[maxCorr2, maxIndex2] = max(abs(correlationAC));
%[maxCorr3, maxIndex3] = max(abs(correlationBC));

% Convert the lag index to time (assuming the audio files are sampled at a certain rate)
deltaTAB = lagAB(maxIndex1) / Fs;
deltaTAC = lagAC(maxIndex2) / Fs;
%deltaTBC = lagBC(maxIndex3) / Fs;

% Define anonymous functions for hyperbolas
hAB = @(x, y) sqrt((x - micApos(1)).^2 + (y - micApos(2)).^2) - sqrt((x - micBpos(1)).^2 + (y - micBpos(2)).^2) - speedofsound * (deltaTAB);
hAC = @(x, y) sqrt((x - micApos(1)).^2 + (y - micApos(2)).^2) - sqrt((x - micCpos(1)).^2 + (y - micCpos(2)).^2) - speedofsound * (deltaTAC);

%Not needed, might be used for higer precision.
%hBC = @(x, y) sqrt((x - micBpos(1)).^2 + (y - micBpos(2)).^2) - sqrt((x - micCpos(1)).^2 + (y - micCpos(2)).^2) - speedofsound * (deltaTBC);

% Estimate sound position by finding the intersection of hyperbolas
f_intersect = @(x) [hAB(x(1), x(2)); hAC(x(1), x(2))];
initial_guess = [0.5, 0.5]; % Initial guess for sound position

%options = optimoptions('fsolve','Algorithm','levenberg-marquardt');
sound_position_estimate = fsolve(f_intersect, initial_guess);
end