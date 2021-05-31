# Le projet

## Version 0.1
Le but du projet est de programmer un compresseur de fichier basé sur la méthode RLE (Run Length Encoding). Cette méthode consiste à remplacer dans un fichier des suites de caractères identiques par 3 caractères. Un caractère ! qui indique le début d'une séquence de remplacement, un caractère chiffre (compris entre 4 et 9) qui indique le nombre de caractères remplacés suivi du caractère effectivement remplacé. Des suites de caractères inférieures à 4 caractères ne sont pas modifiés car le gain serait nul. un caractère ! dans le fichier original est traduit par deux !! dans le fichier compressé

## Version 0.2

Le gain maximal de 6 caractères, est obtenu pour une séquence de 9 caractères identiques consécutifs. Les caractères ! présents dans le fichier d'origine pénalisent l'algorithme car il doivent être doublés. On peut facilement améliorer l'algorithme de deux manières:
* en choisissant un caractère qui n'apparait pas dans le fichier d'origine (ou le caractère le moins fréquent lorsque toutes les valeurs existent) pour indiquer le début d'un séquence de remplacement. Le caractère choisit est simplement indiqué en premier caractère du fichier compressé.
* en choisissant un caractère supplémentaire pour des séquences de 10 à 99 caractères identiques consécutifs. Ce caractère est également choisit parmis les caractères peu fréquents du fichier d'origine et est indiqué en deuxième caractère du fichier compressé.

-----------------

# Exemples

## Version 0.1

Par exemple avec le fichier ci-dessous, le fichier compressé obtenu est

| Fichier  | Fichier compressé |
| :--------------- |:---------------|
| !bonjour!! | !!bonjour!!!! |
| aaaazzzzzzz | !4a!7z |
| jkiiiiii | jk!6i |
| ss | ss |
| sssssssssssdfffff | !9sssd!5f |
| 1111111111111111 | !91!71 |
| xxxxxggg!gnnnnnnn! | !5xggg!!g!7n!! |
| qqqxx | qqqxx |
| lm! | lm!! |

Des séquences de plus de 9 caractères identiques consécutifs sont traduites par deux (ou plus) séquences compressées. Ainsi la séquence de 11 s est traduite par !9sss(9 fois s + ss) et la séquence de 16 1 est traduite par !91!71 (9 fois 1 + 7 fois 1).


## Version 0.2

| Fichier  | Fichier compressé |
| :--------------- |:---------------|
| !bonjour!! | !bonjour!! |
| aaaazzzzzzz | #4a#7z |
| jkiiiiii | jk#6i |
| ss | ss |
| sssssssssssdfffff | #&ssd#5f |
| 1111111111111111 | #&#61 |
| xxxxxggg!gnnnnnnn! | #5xggg!g#7n! |
| qqqxx | qqqxx |
| lm! | lm!! |
!!M3333333333333333333333333lllllllLLLa | !!M#&#&#53#7lLLLa
999999999999999999999999999999 | #&#&#&9

Dans ces exemples, le caractère '#' est utilisé pour indiquer le début d'un séquence de remplacement et le caractère '&' est utilisé pour les séquences de 10 à 99 caractères identiques consécutifs. La séquence '#&' signifie une suite de 10 caractères identiques. La séquences #&#&#&9 signifie une suite de 30 caractères identiques de valeur 9 (10 + 10 + 10).
Ainsi la séquence de 11 s est traduite pas #&ss (10 fois s + s). La séquence de 16 1 est traduite par #&#61 (10 fois 1 + 6 fois 1).  

-----------------

# Environnement de test

Visual Studio Code + extension C/C++ [documentation](https://code.visualstudio.com/docs/cpp/config-msvc) + extension Doxygen Documentation Generator
Windows 10
