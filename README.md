# Systeme-de-gestion-de-produits-C-

Classes composition Catalogue et Produits. Les classes Vetement et Electronique héritent de la classe abstraite Produit
pour permettre la création d'objets Produit qui seront spécifiquement associés à un type de produit. La création d'un
objet produit qui n'est pas spécifié vetement ou electronique ne serait pas réaliste en terme de reproduction d'un
catalogue de produit d'un vrai magasin, ce qui explique le besoin de rendre la classe Produit abstraite.

Catalogue contient un vecteur de pointeurs intelligents vers nos produits (objets) actuellement présents et
c'est cette fonctionnalité qui est principalement utilisée dans notre interface graphique (GUI).

Le projet a été conçu avec Netbeans et l'interface graphique qui permet manuellement d'ajouter, supprimer des
produits a été conçue avec QT.

Ce projet est une base pour gérer des produits dans un catalogue qui a été fait dans le cadre d'un projet de cours.
Il a été documenté avec précision et a été fait avec l'intention de pouvoir être ajusté facilement si l'on veut
ajouter d'autres types de produits (créer d'autres classes héritant de la classe Produit).
