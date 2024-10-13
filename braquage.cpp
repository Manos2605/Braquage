#include<iostream>

// fonction pour vérifier si trois points sont alignés
bool points_Alignes(float x1, float y1, float x2, float y2, float x3, float y3) {
    // calcul du déterminant
    float determinant = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
    if (determinant == 0.0f){
        return true;
    }else{
        return false;
    }
 
}

// fonction pour calculer le centre du cercle circonscrit à trois points non alignés
void Centre_points(float x1, float y1, float x2, float y2, float x3, float y3, float &cx, float &cy) {
    float d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    // coefficients pour trouver les coordonnées du centre
    float ux = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / d;
    float uy = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / d;

    cx = ux;
    cy = uy;
}

int main(){
    int n = 3;


    // tableaux pour stocker les coordonnées des lieux de braquages
    float x[3];
    float y[3];  // Limité à 100 points pour simplifier

    std::cout << "Braquage:" <<std::endl;

    // entrée des coordonnées des braquages
    for (int i = 0; i < n; ++i) {
        std::cout << "-coordonnées "<< i + 1 <<" (x, y) : ";
        std::cin >> x[i] >> y[i];
    }

    // vérifier s'il existe au moins trois points non alignés
    bool possible = false;
    float cx = 0, cy = 0;  // coordonnées du centre potentiel
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