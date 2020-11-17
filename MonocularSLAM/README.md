# Consegna
Creare un terzo componente “MonocularSLAM” (a partire dal codice del componente CameraViewer) che possieda come activity “SlamProcessing” associato ad un file di configurazione. Tale activity ha un subscriber che riceve un’immagine. Deve selezionare e attivare un plug-in (in functionality) che implementa un algoritmo di Slam scelto. Ogni algoritmo deve implementare il proprio plug-in. I plug-in devono essere interscambiabili.

## Hint

I file nella cartella **STAR/RobotNavigation/Functionalities** per ora non vanno modificati.

MonocularSLAM è un duplicato del componente CameraViewer.
Dovete scompattarlo nella cartella
**STAR/RobotNavigation/Components/**

Il vostro punto di partenza è il file
**ImageProcessing.cpp**

La funzione **imageCallback()** si occupa di ricevere i messaggi con le immagini inviate dal componente **CameraServer**.

L'immagine ricevuta è memorizzata nella variabile
**Mat frame** (riga 100)

Le righe 107, 108, 109 creano una finestra in cui viene visualizzata l'immagine ricevuta.
Al posto di queste tre righe dovete scrivere il codice del vostro progetto che elabora un'immagine secondo l'algoritmo di SLAM.

Per ricompilare il componente MonocularSLAM eseguite i seguenti comandi:

`$ cd STAR `

`$ . env-star.sh`

`$ cd RobotNavigation/Components/MonocularSLAM/bin`

`$ . compile`

Per eseguirlo:

`$ cd RobotNavigation/Components/MonocularSLAM/bin`

`$ . run.sh`
