Measurement Program

Detta är ett enkelt C++-konsolprogram för att lagra, analysera och visualisera mätvärden. Programmet låter användaren lägga till mätvärden manuellt eller simulera sensorvärden, visa alla mätvärden, beräkna statistik (summa, min, max, medelvärde, varians och standardavvikelse), sortera värden och visualisera dem som ett ASCII-diagram direkt i konsolen.

Programmet är utformat för att vara enkelt att använda med en tydlig meny och felhantering för ogiltig inmatning. Alla mätvärden lagras i en vector<Measurement> och varje värde representeras av en Measurement-struct.

Funktioner

Lägg till mätvärden manuellt: Ange hur många värden som ska läggas till och skriv in dem ett i taget.

Visa alla mätvärden: Lista alla lagrade mätvärden med deras index.

Visa statistik: Beräkna och visa antal värden, summa, min, max, medelvärde, varians och standardavvikelse.

Sortera värden: Sortera mätvärden i stigande eller fallande ordning.

ASCII-diagram: Visualisera mätvärden som staplar av asterisker.

Simulera sensorvärden: Generera slumpmässiga värden mellan 20 och 30.

Installation

Kompilera programmet med g++:

g++ -o measurement_program main.cpp


Kör programmet:

./measurement_program

Användning

När programmet startar visas en meny med följande val:

Measurement Program
1. Add measurements manually
2. Show all measurements
3. Show statistics
4. Sort values
5. Show ASCII diagram
6. Simulate sensor measurements
7. Exit
Your choice:


Användaren anger ett nummer mellan 1 och 7 för att välja önskad funktion. Programmet validerar inmatningen och uppmanar användaren att skriva ett giltigt värde om inmatningen är felaktig.

Exempel

Om användaren väljer att simulera 5 sensorvärden:

Your choice: 6
How many sensor values to simulate? 5
5 simulated sensor values added.


Visa alla värden:

Your choice: 2

All measurements:
Value 1: 22.47
Value 2: 28.91
Value 3: 25.33
Value 4: 20.88
Value 5: 29.15


Visa ASCII-diagram:

Your choice: 5

ASCII Diagram:
22.47 | ******
28.91 | ********************
25.33 | ***************
20.88 | ****
29.15 | **********************


Visa statistik:

Your choice: 3

Statistics
Count: 5
Sum: 126.74
Min: 20.88
Max: 29.15
Mean: 25.35
Variance: 11.63
Std Dev: 3.41

Kodstruktur

struct Measurement: representerar ett mätvärde.

vector<Measurement> values: lagrar alla mätvärden.

Funktioner:

add_measurements(): lägger till värden manuellt.

show_all_measurements(): visar alla mätvärden.

show_statistics(): beräknar statistik.

sort_values(): sorterar värden.

show_ascii_diagram(): visar diagram.

simulate_sensor(): genererar slumpmässiga värden.

Framtida förbättringar

Spara och läsa mätvärden från fil.

Fler visualiseringsalternativ, t.ex. histogram.

GUI-version för enklare användning.
