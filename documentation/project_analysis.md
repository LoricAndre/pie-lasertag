# Project Analysis

## Analyse d'usage

### Contexte

On souhaite développer un logiciel pour controler le déroulement d'une partie de lasertag.

### Fonctions souhaitées

Le logiciel développé doit gérer les informations recues par les terminaux, les traiter et en retransmettre. Il doit comporter une interface graphique simple d'usage pour l'utilisateur permettant de gérer les modes de jeux utilisés et d'afficher des statistiques en temps réel.

### Interactions

Interactions homme-interface graphique, interface graphique-codes sources et codes sources-terminaux.

### Fonctions de tests de base

Il faut pouvoir tester le comportement du logiciel à la réception de données.
Tester le format des paquets de données recues.

## Analyse fonctionnelle

### Blocs fonctionnels

* fonction de récupération des paramètres entrés par l'utilisateur
* fonction d'affichage des données produites par le gestionnaire de partie
* réception des données envoyés par les terminaux
* envois de données vers les terminaux
* gestion de la partie

### Interactions

Pareil

## Architecture

Code C++ orienté objet si possible.

#### Classes principales

* Personnage
* objets