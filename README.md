# Monocular-SLAM
Localizzazione e costruzione di mappe con immagini da telecamera. Progetto di Robotica 2020-2021.

Il progetto prevede di utilizzare una semplice web cam per stimare gli spostamenti della telecamera
stessa e per rappresentare la posizione e forma degli ostacoli presenti nell’ambiente.
La figura mostra un’immagine fornita da una semplice web cam nella quale sono stati individuati
dei punti caratteristici dell’ambiente (cerchi colorati).
Questi punti caratteristici consentono di stimare lo spostamento della telecamera e forniscono
informazione sulla posizione degli ostacoli

## Descrizione del progetto:
L'obiettivo del progetto consiste nel confrontare sperimentalmente due librerie open source
per monocular SLAM.
- ROS LSDSLAM 
  - https://vision.in.tum.de/research/vslam/lsdslam?redirect=1
  - https://github.com/tum-vision/lsd_slam
- ROS REMODE
  - https://www.ros.org/news/2016/02/open-source-release-remode-probabilistic-monocular-dense-reconstruction-in-real-time.html
  - https://www.youtube.com/watch?v=QTKd5UWCG0Q


Le due librerie sono integrate con il framework ROS https://www.ros.org/ .

Il progetto deve analizzare l’architettura software delle due librerie in modo da separare le funzionalità di
Communication, Computation, Configuration e Coordination (come visto a lezione).


Il progetto deve infine integrare le due librerie con il framework STAR presentato a lezione in ambiente Ubuntu 20.04.


Una volta integrate con il framework STAR, le due librerie verranno messe a confronto per
il rilevamento di ostacoli posti di fronte alla telecamera.
