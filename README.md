# Détection de la Maison du Brigand

Ce projet en C++ détermine la position possible d'une maison de brigand en utilisant les coordonnées de plusieurs braquages. Il vérifie si au moins trois points donnés ne sont pas alignés et calcule ensuite le centre du cercle circonscrit à ces points non alignés. Video d'exécution presente sur X et sur Linkedln: 
- https://x.com/Sonwa_Dimitry/status/1845764699675115757
- https://www.linkedin.com/posts/dimitry-sonwa-132345311_mystaeyre-programmation-github-activity-7251862055983435777-1Yh7?utm_source=share&utm_medium=member_desktop

## Fonctionnalités
- Saisir les coordonnées de trois points.
- Vérifier si les points sont alignés ou non en utilisant le **déterminant**.
- Si les points ne sont pas alignés, calculer les coordonnées du centre du cercle circonscrit à ces trois points.

### Formule du déterminant

Le déterminant permet de vérifier si trois points sont alignés :
\[
\text{Déterminant} = (x2 - x1)*(y3 - y2) - (y2 - y1)*(x3 - x2)
\]
- Si le déterminant est égal à 0, les points sont alignés.

### Formule pour le centre du cercle circonscrit
![Capture d'écran 2024-10-13 192754](https://github.com/user-attachments/assets/b8eddea6-94ce-45c2-822f-1dee1021d4f5)



### Exécution
```
braquage :
- Coordonnées 1 (x, y) : 1 2
- Coordonnées 2 (x, y) : 3 4
- Coordonnées 3 (x, y) : 5 6
Coordonnées possibles de la maison du brigand : (2.5, 1.5)





