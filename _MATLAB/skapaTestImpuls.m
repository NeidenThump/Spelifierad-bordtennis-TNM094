function [signal_matris,fs] = skapaTestImpuls(a,b)
% Mikrofonerna har positionerna (0,0) (0,1) (1,1) och (1,0) [ordnade]
% (0,0) är referensmikrofon som används för beräkning av tidsskillnad
% Skapar 4 kanaler (kolumner) med förskjutningar som motsvarar de beräknade

posA = [0,0];
posB = [1.525, 0];
posC = [0, 1.37];

v = 340;
r = sqrt(a^2+b^2);

%läs in en impuls
[signal, fs] = audioread("pingpongImpuls.wav");

% Tidsförskjutning i sekunder (kan vara negativ)
dt1 = (1/v)*(sqrt((a-posB(1))^2+(b-posB(2))^2)-r);  % tidsskillnad mellan mic 1 och 2
dt2 = (1/v)*(sqrt((a-posC(1))^2+(b-posC(2))^2)-r); % mic 1 och 3
dt3 = (1/v)*(sqrt((1-a)^2+b^2)-r); % mic 1 och 4

% Beräkna antalet sampel för förskjutning
n1 = round(dt1 * fs);
n2 = round(dt2 * fs);
n3 = round(dt3 * fs);

% Funktion för att förskjuta signalen
%shiftSignal = @(signal, n) [max(0, -n); signal(max(1, 1+n):end+min(0, n))];
%shiftSignal = @(signal, n) [zeros(max(0, -n), 1); signal(max(1, 1+n):end+min(0, n - 1))];
shiftSignal = @(signal, n) [zeros(max(0, n), 1); signal(max(1, 1-n):end+min(0, -n))];

% Skapa förskjutna signaler
signal_dt1 = shiftSignal(signal, n1);
signal_dt2 = shiftSignal(signal, n2);
signal_dt3 = shiftSignal(signal, n3);

% Anpassa längden på alla signaler till den längsta signalens längd
maxLength = max([length(signal_dt1), length(signal_dt2), length(signal_dt3), length(signal)]);
signal = [signal; zeros(maxLength - length(signal), 1)];
signal_dt1 = [signal_dt1; zeros(maxLength - length(signal_dt1), 1)];
signal_dt2 = [signal_dt2; zeros(maxLength - length(signal_dt2), 1)];
signal_dt3 = [signal_dt3; zeros(maxLength - length(signal_dt3), 1)];

% Kombinera originalsignalen och de förskjutna signalerna i en matris
signal_matris = [signal, signal_dt1, signal_dt2, signal_dt3];
end