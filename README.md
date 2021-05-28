# Le projet

Le but du projet est de programmer un compresseur de fichier basé sur la méthode RLE (Run Length Encoding). Cette méthode consiste à remplacer dans un fichier des suites de caractères identiques par 3 caractères. Un caractère ! qui indique le début d'une séquence de remplacement, un caractère chiffre (compris entre 4 et 9) qui indique le nombre de caractères remplacés suivi du caractère effectivement remplacé. Des suites de caractères inférieures à 4 caractères ne sont pas modifiés car le gain serait nul. un caractère ! dans le fichier original est traduit par deux !! dans le fichier compressé

-----------------

# Exemples

Par exemple avec le fichier ci-dessous, le fichier compressé obtenu est

!bonjour!!|!!bonjour!!!!
aaaazzzzzzz|!4a!7z
jkiiiiii|jk!6i
ss|ss
sssssssssssdfffff|!9sssd!5f
1111111111111111|!91!71
xxxxxggg!gnnnnnnn!|!5xggg!!g!7n!!
qqqxx|qqqxx
lm!|lm!!

Des séquences de plus de 9 caractères identiques consécutifs sont traduites par deux (ou plus) séquences compressées. Ainsi la séquence de 11 s est traduite par !9sss(9 fois s + ss) et la séquence de 16 1 est traduite par !91!71 (9 fois 1 + 7 fois 1).

-----------------

# Environnement de test

Visual Studio Code + extension C/C++ [documentation](https://code.visualstudio.com/docs/cpp/config-msvc) + extension Doxygen Documentation Generator
Windows 10
