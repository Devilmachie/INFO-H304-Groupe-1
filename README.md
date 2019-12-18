# INFO-H304-Groupe-1
Gilles Petitjean
Célestin Lengelé
Sébastien Berlemont
Complement de programmation et d'algorithmique : projet : PROTEIN SEQUENCE ALIGNMENT USING THE SMITH-WATERMAN ALGORITHM

This program will find the best alignments for a given protein sequence, using the Smith-Waterman algorithm.
To use the program, you will need the following arguments :

[DATABASE] [SEQUENCE] [OPTIONS]

Possible options are :                                                 
-go [GAP_OPEN_PENALTY]         Sets the penalty for opening a gap     (11)
-ge [GAP_EXTENSION_PENALTY]    Sets the penalty for extending a gap   (1)
-blosum [BLOSUM]               Sets the used type of blosum matrix    (BLOSUM62)
-n [NUMBER_OF_RESULTS]         Sets the quantity of returned results  (20)
-t [THREAD_COUNT]              Sets the number of threads used        (4)

The DATABASE has to be in BLAST format, and the SEQUENCE has to be in FASTA format
The values between parenthesis are the default values.
