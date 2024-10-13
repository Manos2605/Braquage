#include<iostream>

// fonction pour vérifier si trois points sont alignés
bool points_Alignes(double x1, double y1, double x2, double y2, double x3, double y3) {
    // calcul du déterminant
    double determinant = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    return determinant == 0;
}

// fonction pour calculer le centre du cercle circonscrit à trois points non alignés
void Centre_points(double x1, double y1, double x2, double y2, double x3, double y3, double &cx, double &cy) {
    double d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    // coefficients pour trouver les coordonnées du centre
    double ux = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / d;
    double uy = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / d;

    cx = ux;
    cy = uy;
}

int main(){
    int n = 3;


    // tableaux pour stocker les coordonnées des lieux de braquages
    double x[3];
    double y[3];  // Limité à 100 points pour simplifier

    std::cout << "Braquage:" <<std::endl;

    // entrée des coordonnées des braquages
    for (int i = 0; i < n; ++i) {
        std::cout << "-coordonnées "<< i + 1 <<" (x, y) : ";
        std::cin >> x[i] >> y[i];
    }

    // vérifier s'il existe au moins trois points non alignés
    bool possible = false;
    double cx = 0, cy = 0;  // coordonnées du centre potentiel
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (!points_Alignes(x[i], y[i], x[j], y[j], x[k], y[k])) {
                    // si les points ne sont pas alignés, calculer le centre du cercle circonscrit
                    Centre_points(x[i], y[i], x[j], y[j], x[k], y[k], cx, cy);
                    possible = true;  // trois points non alignés trouvés
                    break;
                }
            }
            if (possible) break;
        }
        if (possible) break;
    }

    // affichage du résultat
    if (possible) {
        std::cout << "Coordonnées possibles de la maison du brigand : (" << cx << ", " << cy << ")" << std::endl;
    } else {
        std::cout << "Impossible de trouver la maison du brigand, toute les positions sont alignés." << std::endl;
    }

    return 0;
}