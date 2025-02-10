# Simulateur de Bras Robot 3D avec Raylib

Ce projet est un simulateur de bras robot 3D en C utilisant la bibliothèque Raylib pour le rendu graphique. Le simulateur permet de contrôler les différents axes du bras robot à l'aide des touches du clavier, tout en respectant les limites de mouvement.

## Fonctionnalités

- **Simulation 3D** : Visualisation en temps réel du bras robot en 3D.
- **Contrôle par Clavier** : Utilisation des touches du clavier pour déplacer les axes du bras robot.
- **Limites de Mouvement** : Respect des contraintes physiques et des limites de mouvement du bras robot.
- **Interface Utilisateur** : Affichage des informations de position et d'état du bras robot.

## Prérequis

- Compilateur C (par exemple, GCC)
- Bibliothèque Raylib (disponible sur [raylib.com](https://www.raylib.com/))

## Installation

1. **Installer Raylib** : Suivez les instructions d'installation de Raylib pour votre système d'exploitation sur le site officiel.
2. **Cloner le Dépôt** :
   ```bash
   git clone https://github.com/CharlilouM/3D_arm_simu/
   cd 3D_arm_simu
   ```
3. **Compiler le Projet** :
   ```bash
   make
   ```

## Utilisation

1. **Exécuter le Programme** :
   ```bash
   ./simu
   ```
2. **Contrôles Clavier** :
   - Utilisez les touches fléchées ou des touches spécifiques (par exemple, `1`, `2`, `3`, `4`) pour contrôler les différents axes du bras robot.
