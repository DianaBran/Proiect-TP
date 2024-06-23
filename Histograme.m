% URL-urile pentru conținutul raw al fișierelor
normal_url = 'https://raw.githubusercontent.com/DianaBran/Proiect-TP/main/normal_distribution.txt';
poisson_url = 'https://raw.githubusercontent.com/DianaBran/Proiect-TP/main/poisson_distribution.txt';

% Citește datele
normal_data = webread(normal_url);
poisson_data = webread(poisson_url);

% Convertește datele din string în numere
normal_data = str2double(strsplit(normal_data, '\n'));
poisson_data = str2double(strsplit(poisson_data, '\n'));

% Elimină orice valoare NaN (care ar putea rezulta din linii goale)
normal_data = normal_data(~isnan(normal_data));
poisson_data = poisson_data(~isnan(poisson_data));

% Histograma pentru distribuția normală
figure;
histogram(normal_data, 50, 'Normalization', 'probability');
title('Histograma Distribuției Normale');
xlabel('Valoare');
ylabel('Probabilitate');

% Histograma pentru distribuția Poisson
figure;
histogram(poisson_data, 'Normalization', 'probability');
title('Histograma Distribuției Poisson');
xlabel('Valoare');
ylabel('Probabilitate');