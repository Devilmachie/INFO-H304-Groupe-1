#include "database.h"

const char mat_blosum45[] = 
"# Entries for the BLOSUM45 matrix at a scale of ln(2)/3.0.\n\
   A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V  B  J  Z  X  *\n\
A  5 -2 -1 -2 -1 -1 -1  0 -2 -1 -1 -1 -1 -2 -1  1  0 -2 -2  0 -1 -1 -1 -1 -5\n\
R -2  7  0 -1 -3  1  0 -2  0 -3 -2  3 -1 -2 -2 -1 -1 -2 -1 -2 -1 -3  1 -1 -5\n\
N -1  0  6  2 -2  0  0  0  1 -2 -3  0 -2 -2 -2  1  0 -4 -2 -3  5 -3  0 -1 -5\n\
D -2 -1  2  7 -3  0  2 -1  0 -4 -3  0 -3 -4 -1  0 -1 -4 -2 -3  6 -3  1 -1 -5\n\
C -1 -3 -2 -3 12 -3 -3 -3 -3 -3 -2 -3 -2 -2 -4 -1 -1 -5 -3 -1 -2 -2 -3 -1 -5\n\
Q -1  1  0  0 -3  6  2 -2  1 -2 -2  1  0 -4 -1  0 -1 -2 -1 -3  0 -2  4 -1 -5\n\
E -1  0  0  2 -3  2  6 -2  0 -3 -2  1 -2 -3  0  0 -1 -3 -2 -3  1 -3  5 -1 -5\n\
G  0 -2  0 -1 -3 -2 -2  7 -2 -4 -3 -2 -2 -3 -2  0 -2 -2 -3 -3 -1 -4 -2 -1 -5\n\
H -2  0  1  0 -3  1  0 -2 10 -3 -2 -1  0 -2 -2 -1 -2 -3  2 -3  0 -2  0 -1 -5\n\
I -1 -3 -2 -4 -3 -2 -3 -4 -3  5  2 -3  2  0 -2 -2 -1 -2  0  3 -3  4 -3 -1 -5\n\
L -1 -2 -3 -3 -2 -2 -2 -3 -2  2  5 -3  2  1 -3 -3 -1 -2  0  1 -3  4 -2 -1 -5\n\
K -1  3  0  0 -3  1  1 -2 -1 -3 -3  5 -1 -3 -1 -1 -1 -2 -1 -2  0 -3  1 -1 -5\n\
M -1 -1 -2 -3 -2  0 -2 -2  0  2  2 -1  6  0 -2 -2 -1 -2  0  1 -2  2 -1 -1 -5\n\
F -2 -2 -2 -4 -2 -4 -3 -3 -2  0  1 -3  0  8 -3 -2 -1  1  3  0 -3  1 -3 -1 -5\n\
P -1 -2 -2 -1 -4 -1  0 -2 -2 -2 -3 -1 -2 -3  9 -1 -1 -3 -3 -3 -2 -3 -1 -1 -5\n\
S  1 -1  1  0 -1  0  0  0 -1 -2 -3 -1 -2 -2 -1  4  2 -4 -2 -1  0 -2  0 -1 -5\n\
T  0 -1  0 -1 -1 -1 -1 -2 -2 -1 -1 -1 -1 -1 -1  2  5 -3 -1  0  0 -1 -1 -1 -5\n\
W -2 -2 -4 -4 -5 -2 -3 -2 -3 -2 -2 -2 -2  1 -3 -4 -3 15  3 -3 -4 -2 -2 -1 -5\n\
Y -2 -1 -2 -2 -3 -1 -2 -3  2  0  0 -1  0  3 -3 -2 -1  3  8 -1 -2  0 -2 -1 -5\n\
V  0 -2 -3 -3 -1 -3 -3 -3 -3  3  1 -2  1  0 -3 -1  0 -3 -1  5 -3  2 -3 -1 -5\n\
B -1 -1  5  6 -2  0  1 -1  0 -3 -3  0 -2 -3 -2  0  0 -4 -2 -3  5 -3  1 -1 -5\n\
J -1 -3 -3 -3 -2 -2 -3 -4 -2  4  4 -3  2  1 -3 -2 -1 -2  0  2 -3  4 -2 -1 -5\n\
Z -1  1  0  1 -3  4  5 -2  0 -3 -2  1 -1 -3 -1  0 -1 -2 -2 -3  1 -2  5 -1 -5\n\
X -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -5\n\
* -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5  1\n";

const char mat_blosum50[] =
"# Entries for the BLOSUM50 matrix at a scale of ln(2)/3.0.\n\
   A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V  B  J  Z  X  *\n\
A  5 -2 -1 -2 -1 -1 -1  0 -2 -1 -2 -1 -1 -3 -1  1  0 -3 -2  0 -2 -2 -1 -1 -5\n\
R -2  7 -1 -2 -4  1  0 -3  0 -4 -3  3 -2 -3 -3 -1 -1 -3 -1 -3 -1 -3  0 -1 -5\n\
N -1 -1  7  2 -2  0  0  0  1 -3 -4  0 -2 -4 -2  1  0 -4 -2 -3  5 -4  0 -1 -5\n\
D -2 -2  2  8 -4  0  2 -1 -1 -4 -4 -1 -4 -5 -1  0 -1 -5 -3 -4  6 -4  1 -1 -5\n\
C -1 -4 -2 -4 13 -3 -3 -3 -3 -2 -2 -3 -2 -2 -4 -1 -1 -5 -3 -1 -3 -2 -3 -1 -5\n\
Q -1  1  0  0 -3  7  2 -2  1 -3 -2  2  0 -4 -1  0 -1 -1 -1 -3  0 -3  4 -1 -5\n\
E -1  0  0  2 -3  2  6 -3  0 -4 -3  1 -2 -3 -1 -1 -1 -3 -2 -3  1 -3  5 -1 -5\n\
G  0 -3  0 -1 -3 -2 -3  8 -2 -4 -4 -2 -3 -4 -2  0 -2 -3 -3 -4 -1 -4 -2 -1 -5\n\
H -2  0  1 -1 -3  1  0 -2 10 -4 -3  0 -1 -1 -2 -1 -2 -3  2 -4  0 -3  0 -1 -5\n\
I -1 -4 -3 -4 -2 -3 -4 -4 -4  5  2 -3  2  0 -3 -3 -1 -3 -1  4 -4  4 -3 -1 -5\n\
L -2 -3 -4 -4 -2 -2 -3 -4 -3  2  5 -3  3  1 -4 -3 -1 -2 -1  1 -4  4 -3 -1 -5\n\
K -1  3  0 -1 -3  2  1 -2  0 -3 -3  6 -2 -4 -1  0 -1 -3 -2 -3  0 -3  1 -1 -5\n\
M -1 -2 -2 -4 -2  0 -2 -3 -1  2  3 -2  7  0 -3 -2 -1 -1  0  1 -3  2 -1 -1 -5\n\
F -3 -3 -4 -5 -2 -4 -3 -4 -1  0  1 -4  0  8 -4 -3 -2  1  4 -1 -4  1 -4 -1 -5\n\
P -1 -3 -2 -1 -4 -1 -1 -2 -2 -3 -4 -1 -3 -4 10 -1 -1 -4 -3 -3 -2 -3 -1 -1 -5\n\
S  1 -1  1  0 -1  0 -1  0 -1 -3 -3  0 -2 -3 -1  5  2 -4 -2 -2  0 -3  0 -1 -5\n\
T  0 -1  0 -1 -1 -1 -1 -2 -2 -1 -1 -1 -1 -2 -1  2  5 -3 -2  0  0 -1 -1 -1 -5\n\
W -3 -3 -4 -5 -5 -1 -3 -3 -3 -3 -2 -3 -1  1 -4 -4 -3 15  2 -3 -5 -2 -2 -1 -5\n\
Y -2 -1 -2 -3 -3 -1 -2 -3  2 -1 -1 -2  0  4 -3 -2 -2  2  8 -1 -3 -1 -2 -1 -5\n\
V  0 -3 -3 -4 -1 -3 -3 -4 -4  4  1 -3  1 -1 -3 -2  0 -3 -1  5 -3  2 -3 -1 -5\n\
B -2 -1  5  6 -3  0  1 -1  0 -4 -4  0 -3 -4 -2  0  0 -5 -3 -3  6 -4  1 -1 -5\n\
J -2 -3 -4 -4 -2 -3 -3 -4 -3  4  4 -3  2  1 -3 -3 -1 -2 -1  2 -4  4 -3 -1 -5\n\
Z -1  0  0  1 -3  4  5 -2  0 -3 -3  1 -1 -4 -1  0 -1 -2 -2 -3  1 -3  5 -1 -5\n\
X -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -5\n\
* -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5 -5  1\n";

const char mat_blosum62[] =
"# Entries for the BLOSUM62 matrix at a scale of ln(2)/2.0.\n\
   A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V  B  J  Z  X  *\n\
A  4 -1 -2 -2  0 -1 -1  0 -2 -1 -1 -1 -1 -2 -1  1  0 -3 -2  0 -2 -1 -1 -1 -4\n\
R -1  5  0 -2 -3  1  0 -2  0 -3 -2  2 -1 -3 -2 -1 -1 -3 -2 -3 -1 -2  0 -1 -4\n\
N -2  0  6  1 -3  0  0  0  1 -3 -3  0 -2 -3 -2  1  0 -4 -2 -3  4 -3  0 -1 -4\n\
D -2 -2  1  6 -3  0  2 -1 -1 -3 -4 -1 -3 -3 -1  0 -1 -4 -3 -3  4 -3  1 -1 -4\n\
C  0 -3 -3 -3  9 -3 -4 -3 -3 -1 -1 -3 -1 -2 -3 -1 -1 -2 -2 -1 -3 -1 -3 -1 -4\n\
Q -1  1  0  0 -3  5  2 -2  0 -3 -2  1  0 -3 -1  0 -1 -2 -1 -2  0 -2  4 -1 -4\n\
E -1  0  0  2 -4  2  5 -2  0 -3 -3  1 -2 -3 -1  0 -1 -3 -2 -2  1 -3  4 -1 -4\n\
G  0 -2  0 -1 -3 -2 -2  6 -2 -4 -4 -2 -3 -3 -2  0 -2 -2 -3 -3 -1 -4 -2 -1 -4\n\
H -2  0  1 -1 -3  0  0 -2  8 -3 -3 -1 -2 -1 -2 -1 -2 -2  2 -3  0 -3  0 -1 -4\n\
I -1 -3 -3 -3 -1 -3 -3 -4 -3  4  2 -3  1  0 -3 -2 -1 -3 -1  3 -3  3 -3 -1 -4\n\
L -1 -2 -3 -4 -1 -2 -3 -4 -3  2  4 -2  2  0 -3 -2 -1 -2 -1  1 -4  3 -3 -1 -4\n\
K -1  2  0 -1 -3  1  1 -2 -1 -3 -2  5 -1 -3 -1  0 -1 -3 -2 -2  0 -3  1 -1 -4\n\
M -1 -1 -2 -3 -1  0 -2 -3 -2  1  2 -1  5  0 -2 -1 -1 -1 -1  1 -3  2 -1 -1 -4\n\
F -2 -3 -3 -3 -2 -3 -3 -3 -1  0  0 -3  0  6 -4 -2 -2  1  3 -1 -3  0 -3 -1 -4\n\
P -1 -2 -2 -1 -3 -1 -1 -2 -2 -3 -3 -1 -2 -4  7 -1 -1 -4 -3 -2 -2 -3 -1 -1 -4\n\
S  1 -1  1  0 -1  0  0  0 -1 -2 -2  0 -1 -2 -1  4  1 -3 -2 -2  0 -2  0 -1 -4\n\
T  0 -1  0 -1 -1 -1 -1 -2 -2 -1 -1 -1 -1 -2 -1  1  5 -2 -2  0 -1 -1 -1 -1 -4\n\
W -3 -3 -4 -4 -2 -2 -3 -2 -2 -3 -2 -3 -1  1 -4 -3 -2 11  2 -3 -4 -2 -2 -1 -4\n\
Y -2 -2 -2 -3 -2 -1 -2 -3  2 -1 -1 -2 -1  3 -3 -2 -2  2  7 -1 -3 -1 -2 -1 -4\n\
V  0 -3 -3 -3 -1 -2 -2 -3 -3  3  1 -2  1 -1 -2 -2  0 -3 -1  4 -3  2 -2 -1 -4\n\
B -2 -1  4  4 -3  0  1 -1  0 -3 -4  0 -3 -3 -2  0 -1 -4 -3 -3  4 -3  0 -1 -4\n\
J -1 -2 -3 -3 -1 -2 -3 -4 -3  3  3 -3  2  0 -3 -2 -1 -2 -1  2 -3  3 -3 -1 -4\n\
Z -1  0  0  1 -3  4  4 -2  0 -3 -3  1 -1 -3 -1  0 -1 -2 -2 -2  0 -3  4 -1 -4\n\
X -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -4\n\
* -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4  1\n";

const char mat_blosum80[] =
"# Entries for the BLOSUM80 matrix at a scale of ln(2)/2.0.\n\
   A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V  B  J  Z  X  *\n\
A  5 -2 -2 -2 -1 -1 -1  0 -2 -2 -2 -1 -1 -3 -1  1  0 -3 -2  0 -2 -2 -1 -1 -6\n\
R -2  6 -1 -2 -4  1 -1 -3  0 -3 -3  2 -2 -4 -2 -1 -1 -4 -3 -3 -1 -3  0 -1 -6\n\
N -2 -1  6  1 -3  0 -1 -1  0 -4 -4  0 -3 -4 -3  0  0 -4 -3 -4  5 -4  0 -1 -6\n\
D -2 -2  1  6 -4 -1  1 -2 -2 -4 -5 -1 -4 -4 -2 -1 -1 -6 -4 -4  5 -5  1 -1 -6\n\
C -1 -4 -3 -4  9 -4 -5 -4 -4 -2 -2 -4 -2 -3 -4 -2 -1 -3 -3 -1 -4 -2 -4 -1 -6\n\
Q -1  1  0 -1 -4  6  2 -2  1 -3 -3  1  0 -4 -2  0 -1 -3 -2 -3  0 -3  4 -1 -6\n\
E -1 -1 -1  1 -5  2  6 -3  0 -4 -4  1 -2 -4 -2  0 -1 -4 -3 -3  1 -4  5 -1 -6\n\
G  0 -3 -1 -2 -4 -2 -3  6 -3 -5 -4 -2 -4 -4 -3 -1 -2 -4 -4 -4 -1 -5 -3 -1 -6\n\
H -2  0  0 -2 -4  1  0 -3  8 -4 -3 -1 -2 -2 -3 -1 -2 -3  2 -4 -1 -4  0 -1 -6\n\
I -2 -3 -4 -4 -2 -3 -4 -5 -4  5  1 -3  1 -1 -4 -3 -1 -3 -2  3 -4  3 -4 -1 -6\n\
L -2 -3 -4 -5 -2 -3 -4 -4 -3  1  4 -3  2  0 -3 -3 -2 -2 -2  1 -4  3 -3 -1 -6\n\
K -1  2  0 -1 -4  1  1 -2 -1 -3 -3  5 -2 -4 -1 -1 -1 -4 -3 -3 -1 -3  1 -1 -6\n\
M -1 -2 -3 -4 -2  0 -2 -4 -2  1  2 -2  6  0 -3 -2 -1 -2 -2  1 -3  2 -1 -1 -6\n\
F -3 -4 -4 -4 -3 -4 -4 -4 -2 -1  0 -4  0  6 -4 -3 -2  0  3 -1 -4  0 -4 -1 -6\n\
P -1 -2 -3 -2 -4 -2 -2 -3 -3 -4 -3 -1 -3 -4  8 -1 -2 -5 -4 -3 -2 -4 -2 -1 -6\n\
S  1 -1  0 -1 -2  0  0 -1 -1 -3 -3 -1 -2 -3 -1  5  1 -4 -2 -2  0 -3  0 -1 -6\n\
T  0 -1  0 -1 -1 -1 -1 -2 -2 -1 -2 -1 -1 -2 -2  1  5 -4 -2  0 -1 -1 -1 -1 -6\n\
W -3 -4 -4 -6 -3 -3 -4 -4 -3 -3 -2 -4 -2  0 -5 -4 -4 11  2 -3 -5 -3 -3 -1 -6\n\
Y -2 -3 -3 -4 -3 -2 -3 -4  2 -2 -2 -3 -2  3 -4 -2 -2  2  7 -2 -3 -2 -3 -1 -6\n\
V  0 -3 -4 -4 -1 -3 -3 -4 -4  3  1 -3  1 -1 -3 -2  0 -3 -2  4 -4  2 -3 -1 -6\n\
B -2 -1  5  5 -4  0  1 -1 -1 -4 -4 -1 -3 -4 -2  0 -1 -5 -3 -4  5 -4  0 -1 -6\n\
J -2 -3 -4 -5 -2 -3 -4 -5 -4  3  3 -3  2  0 -4 -3 -1 -3 -2  2 -4  3 -3 -1 -6\n\
Z -1  0  0  1 -4  4  5 -3  0 -4 -3  1 -1 -4 -2  0 -1 -3 -3 -3  0 -3  5 -1 -6\n\
X -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -6\n\
* -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6  1\n";

const char mat_blosum90[] =
"# Entries for the BLOSUM90 matrix at a scale of ln(2)/2.0.\n\
   A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V  B  J  Z  X  *\n\
A  5 -2 -2 -3 -1 -1 -1  0 -2 -2 -2 -1 -2 -3 -1  1  0 -4 -3 -1 -2 -2 -1 -1 -6\n\
R -2  6 -1 -3 -5  1 -1 -3  0 -4 -3  2 -2 -4 -3 -1 -2 -4 -3 -3 -2 -3  0 -1 -6\n\
N -2 -1  7  1 -4  0 -1 -1  0 -4 -4  0 -3 -4 -3  0  0 -5 -3 -4  5 -4 -1 -1 -6\n\
D -3 -3  1  7 -5 -1  1 -2 -2 -5 -5 -1 -4 -5 -3 -1 -2 -6 -4 -5  5 -5  1 -1 -6\n\
C -1 -5 -4 -5  9 -4 -6 -4 -5 -2 -2 -4 -2 -3 -4 -2 -2 -4 -4 -2 -4 -2 -5 -1 -6\n\
Q -1  1  0 -1 -4  7  2 -3  1 -4 -3  1  0 -4 -2 -1 -1 -3 -3 -3 -1 -3  5 -1 -6\n\
E -1 -1 -1  1 -6  2  6 -3 -1 -4 -4  0 -3 -5 -2 -1 -1 -5 -4 -3  1 -4  5 -1 -6\n\
G  0 -3 -1 -2 -4 -3 -3  6 -3 -5 -5 -2 -4 -5 -3 -1 -3 -4 -5 -5 -2 -5 -3 -1 -6\n\
H -2  0  0 -2 -5  1 -1 -3  8 -4 -4 -1 -3 -2 -3 -2 -2 -3  1 -4 -1 -4  0 -1 -6\n\
I -2 -4 -4 -5 -2 -4 -4 -5 -4  5  1 -4  1 -1 -4 -3 -1 -4 -2  3 -5  3 -4 -1 -6\n\
L -2 -3 -4 -5 -2 -3 -4 -5 -4  1  5 -3  2  0 -4 -3 -2 -3 -2  0 -5  4 -4 -1 -6\n\
K -1  2  0 -1 -4  1  0 -2 -1 -4 -3  6 -2 -4 -2 -1 -1 -5 -3 -3 -1 -3  1 -1 -6\n\
M -2 -2 -3 -4 -2  0 -3 -4 -3  1  2 -2  7 -1 -3 -2 -1 -2 -2  0 -4  2 -2 -1 -6\n\
F -3 -4 -4 -5 -3 -4 -5 -5 -2 -1  0 -4 -1  7 -4 -3 -3  0  3 -2 -4  0 -4 -1 -6\n\
P -1 -3 -3 -3 -4 -2 -2 -3 -3 -4 -4 -2 -3 -4  8 -2 -2 -5 -4 -3 -3 -4 -2 -1 -6\n\
S  1 -1  0 -1 -2 -1 -1 -1 -2 -3 -3 -1 -2 -3 -2  5  1 -4 -3 -2  0 -3 -1 -1 -6\n\
T  0 -2  0 -2 -2 -1 -1 -3 -2 -1 -2 -1 -1 -3 -2  1  6 -4 -2 -1 -1 -2 -1 -1 -6\n\
W -4 -4 -5 -6 -4 -3 -5 -4 -3 -4 -3 -5 -2  0 -5 -4 -4 11  2 -3 -6 -3 -4 -1 -6\n\
Y -3 -3 -3 -4 -4 -3 -4 -5  1 -2 -2 -3 -2  3 -4 -3 -2  2  8 -3 -4 -2 -3 -1 -6\n\
V -1 -3 -4 -5 -2 -3 -3 -5 -4  3  0 -3  0 -2 -3 -2 -1 -3 -3  5 -4  1 -3 -1 -6\n\
B -2 -2  5  5 -4 -1  1 -2 -1 -5 -5 -1 -4 -4 -3  0 -1 -6 -4 -4  5 -5  0 -1 -6\n\
J -2 -3 -4 -5 -2 -3 -4 -5 -4  3  4 -3  2  0 -4 -3 -2 -3 -2  1 -5  4 -4 -1 -6\n\
Z -1  0 -1  1 -5  5  5 -3  0 -4 -4  1 -2 -4 -2 -1 -1 -4 -3 -3  0 -4  5 -1 -6\n\
X -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -6\n\
* -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6 -6  1\n";


DataBase::DataBase(char* db_name)
{

	is_open.insert(std::pair<char*,bool>(GENERAL,false));
	is_open.insert(std::pair<char*,bool>(HEADER,false));
	is_open.insert(std::pair<char*,bool>(SEQUENCE,false));
	path_to_db=db_name;
	init_db();
}

DataBase::~DataBase()
{
	std::map<char*, bool>::iterator it;
	for (it = is_open.begin(); it != is_open.end() ; it++)
	{
		if(it->second)
			closeDB(it->first);
	}
	
}

bool DataBase::anotherDBAlreadyOpen()
{
	bool isAlreadyOpen=false;
	std::map<char*, bool>::iterator it;
	for (it = is_open.begin(); it != is_open.end() && !isAlreadyOpen; it++)
        {
        	if(it->second)
		{
			isAlreadyOpen=true;
			std::cout<<"DB file is already opened with extension : "<<it->first<<std::endl;
		}
        }
	return isAlreadyOpen;
}
void DataBase::openDB(char* mode)
{
	if(!anotherDBAlreadyOpen())
	{
		string db_path = (string) path_to_db + mode;
		read_in_db.open(db_path,ios::in|ios::binary);	
		if(read_in_db)	
			is_open[mode]=true;
		else 
			std::cout<<"problem with opening file with extension : "<<mode<<std::endl;
	}

}

void DataBase::closeDB(char* mode)
{
	if(is_open[mode])
	{
		read_in_db.close();
		is_open[mode]=false;	
		//std::cout<<"Closed DB with extension : "<<mode<<std::endl;
	}
}


void DataBase::init_db()
{
	openDB(GENERAL);
	if(is_open[GENERAL])
	{
		this->version.setData(this->read_in_db);
		this->db_type.setData(this->read_in_db);
		this->title_len.setData(this->read_in_db);
		this->title.setData(this->read_in_db, true, *(this->title_len).getData());
		this->t_stamp_len.setData(this->read_in_db);
		this->t_stamp.setData(this->read_in_db, true, *(this->t_stamp_len).getData());
		this->N.setData(this->read_in_db);
		this->res_n.setData(this->read_in_db);
		this->max_s_len.setData(this->read_in_db);
		this->offset_h.setData(this->read_in_db, true, *(this->N).getData() + 1);
		this->offset_r.setData(this->read_in_db, true, *(this->N).getData() + 1);

		closeDB(GENERAL);
	}
	else
		std::cout<<"DB couldn't be open"<<std::endl;
	
}

int DataBase::getvalue(char c){
	switch(c){
		case 'A': return 0;
		case 'B': return 1;
		case 'C': return 2;
		case 'D': return 3;
		case 'E': return 4;
		case 'F': return 5;
		case 'G': return 6;
		case 'H': return 7;
		case 'I': return 8;
		case 'K': return 9;
		case 'L': return 10;
		case 'M': return 11;
		case 'N': return 12;
		case 'P': return 13;
		case 'Q': return 14;
		case 'R': return 15;
		case 'S': return 16;
		case 'T': return 17;
		case 'V': return 18;
		case 'W': return 19;
		case 'X': return 20;
		case 'Y': return 21;
		case 'Z': return 22;
		case 'J': return 23;
		case '*': return 24;
		case ' ':;
	}
}

void DataBase::create_subst_mat(const char* blosum, size_t blosumsize, int *matrix, size_t matrixsize) {
	
	if(matrixsize != 625) {
		std::cout << "Matrix not of good size" << endl;
	}
	else{
		int order[25] ={0};
		int limit = blosumsize;//sizeof(blosum[0]);
		//std::cout << "limite : " << limit << " =? " << sizeof(blosum62) << endl;
		int orderbegin = 0;
		int i = 0;
		int j = 0;
		int len = 77; // length of a line of char values
		
		
		for(i = 0 ; i < 100; i++){ // don't read the lines beginning with #
			if(blosum[i] == '#'){
				while(blosum[i] != '\n'){
					i++;
				}
				i++;
				orderbegin = i;
				break;
			}
		}	
		
		int k = 0;
		for(j = orderbegin; blosum[j] != '\n'; j++){ //read the order of the AA and store in order[]
			if(blosum[j] != ' '){
				order[k] = getvalue(blosum[j]);
				k++;
			}
		}
		
		for(int b = 0; b < 25; b++){ // test if order correct
			//std::cout << order[b] << ',' << endl;
		}
		int newbeg = j+1;
		//std::cout << newbeg << endl;
		
		for(int h = 0; h < 25; h++){ // each of the 24 lines
			int aa = getvalue(blosum[newbeg]);

				
			//std::cout << blosum[newbeg]  << " " << getvalue(blosum[newbeg+h*len]) << " H :" << h << " AA value :" << aa << endl;
			k = 0;
			//std::cout << newbeg+1 << endl;
			for(int n = newbeg+1; (blosum[n] != '\n') && (n < limit) ; n++){ 
				

				int value = 0;
				if(blosum[n] == ' '){
					//do nothing
				}
				
				else if(blosum[n] == '-'){ //case of negative value
					n++;
					int pos = aa*25 + order[k];
					//std::cout << -(int)(blosum[n]-'0') << " "<<  pos << endl;
					value = -(int)(blosum[n]-'0');
					//std::cout << "AA :" << aa << " Value :" << value << " k :" << k <<" Pos :" << pos << endl;
					matrix[pos] = value; //std::cout << value << endl;
					k++;
				}
				else { //case of positive value
					int pos = aa*25 + order[k];
					
					if( (blosum[n+1] == ' ') || (blosum[n+1] == '\n') ){ //one digit
						value = (int)(blosum[n]-'0');
					}
					else{ //two digit
						value = ((int)(blosum[n]-'0'))*10 + (int)(blosum[n+1]-'0');
						n++;
					}
					//std::cout << "AA :" << aa << " Value :" << value << " k :" << k <<" Pos :" << pos << endl;
					matrix[pos] = value;// std::cout << value << endl;
					k++;
				}
			}
			k = 0;
			newbeg += len;	
		}	
	}
}

int DataBase::find_blosum(){
	int matrix[625] = {0}; // initialize matrix to all 0 values
	create_subst_mat(mat_blosum62, sizeof(mat_blosum62), matrix, (sizeof(matrix)/sizeof(matrix[0])) );
	
	for(int x = 0; x < 25; x++){ // check if matrix has been changed
		for(int y = 0; y < 25; y++){
			//std::cout << matrix[x*25+y] << ' ' ;
			BLOSUM[x*25+y] = matrix[x*25+y];
		}
		//std::cout << endl;
	}
	
	return 0;
}

void DataBase::print_header(uint32_t offset, int size){
	bool found_header;
		
	//finds header size and offset
	char* full_header_name=new char[size];	
		
	fishData(read_in_db,full_header_name,offset,size);
			
	//only keeps clean string
	found_header=false;
	for (int j=0; !found_header; j++)
	{
		//find beginning of sequence
		if( full_header_name[j]==0x1A ){
			//find length
			size = (int) full_header_name[j+1];
			offset = j+2;
				
			//if long header TO DO !!!!!!!
			if ( size < 0x00)
			{
				if (size != -127 )
					std::cout << "name too long : "<< size << std::endl;
				offset++;
				size = (int) full_header_name[j+2]+256;
			}
				
			//makes sure next isn't another string/sequence/choice
			if (full_header_name[offset]!=0x30 && full_header_name[offset]!=0xA1 && full_header_name[offset]!=0xA0 && full_header_name[offset]!=0x1A )
			{
				found_header=true;
				char* header_name=new char[size]; 
				for (int k=0; k<size; k++)
					header_name[k]=full_header_name[offset+k];
				delete full_header_name;
				std::cout<<header_name<<std::endl;
				delete header_name; 
			}
			
		}

	}

}

void DataBase::showDBInfo()
{
	std::cout<<"____________________________________________________________________________"<<std::endl;
	std::cout<<"---NAME_Len : "<< (title).getData() <<std::endl; // recoit un pointeur vers 
	std::cout<<"\n---version : "<< *(version).getData() <<std::endl;
	std::cout<<"\n---db_type : "<< *(db_type).getData() <<std::endl;
	std::cout<<"\n---time_stamp : "<< (t_stamp).getData() <<std::endl;
	std::cout<<"\n---nbr_of_sequences in DB : "<<*(N).getData() <<std::endl;
	std::cout<<"\n---longest sequence in DB : "<<*(max_s_len).getData() <<std::endl;
	std::cout<<"____________________________________________________________________________"<<std::endl;
}

void DataBase::fishData(ifstream & fp,char* buffer,uint32_t offset,uint32_t size)
{
	fp.seekg(offset,fp.beg);
	fp.read(buffer,size);
}

int DataBase::fill_matrix(short*** scoring_m, char* found_sequence, int found_length, char* searched_sequence, int searched_length)
{
	short up_score;
	short left_score;
	short diag_score;
	//int min;
	short score;
	short highest_score=0;
	
	short h_gap;
	short v_gap[searched_length];
	
	//first NULL lines
	for (short i=0; i<=searched_length; i++)
		(*scoring_m)[0][i]=0;
	for (short i=1; i<=found_length; i++)
		(*scoring_m)[i][0]=0;
		
	for (short i=0; i<searched_length; i++)
		v_gap[i]=0;
		
	
	//fills the scoring matrix
	for (short i=1; i<=found_length; i++)
	{
		h_gap=0;
		
		for (short j=1; j<=searched_length; j++)
		{
			if ( !v_gap[j-1] ) 
				{ up_score = (*scoring_m)[i-1][j] - GAP_PENALTY; }
			else
				up_score = (*scoring_m)[i-1][j] - EXTENSION_PENALTY;
				
			if ( !h_gap )
				{ left_score = (int) (*scoring_m)[i][j-1] - GAP_PENALTY; }
			else
				left_score = (int) (*scoring_m)[i][j-1] - EXTENSION_PENALTY;
				
			diag_score = (int) (*scoring_m)[i-1][j-1] +  BLOSUM[25*(found_sequence[i-1]-1)+searched_sequence[j-1]-1];
			
			//max
			if(up_score<left_score)
			{
				if(diag_score<left_score)
					score=left_score;
				else
					score=diag_score;
			}
			else
			{
				if(diag_score<up_score)
					score=up_score;
				else
					score=diag_score;
			}
			
			
			if(score==up_score)
				v_gap[j-1]++;
			else
				v_gap[j-1]=0;
			
			if(score==left_score)
				h_gap++;
			else
				h_gap=0;
			
			
			(*scoring_m)[i][j]=score;
			
			if(score>highest_score)
				highest_score=score;
			 
		}
	}
	
	return highest_score;
	
}

void *DataBase::main_loop(Sequence* vargp, short t_offset)
{
	Sequence* searched_sequence = (Sequence*) vargp;
	char* read_data = new char[*(max_s_len).getData()];
	uint32_t i_max = *(N).getData(), actual_offset=0, actual_size=0;
	uint32_t* offset_residue= (offset_r).getData();
	uint32_t* offset_header = (offset_h).getData();
	int score, header_size, min;
	
    	if(!is_open[SEQUENCE])
    	{
        	std::cout<<"DB couldn't be opened"<<std::endl;
        	return (void*) hasBeenFound;
    	}
	
	find_blosum();
		
	
	for(int i=t_offset; i<i_max; i=i+THREAD_COUNT)
	{ 
		actual_offset=*(offset_residue+i);
		actual_size=*(offset_residue+i+1)-*(offset_residue+i);
		while(reading)
			;
		reading = true;
		fishData(read_in_db,read_data,actual_offset,actual_size);
		reading = false;
		
		short** scoring_m = new short*[(actual_size+1)];
		for (short i=0; i<=actual_size; i++)
			scoring_m[i]=new short[(searched_sequence->getDataLen()+1)];
		
		score = fill_matrix(&scoring_m, read_data, actual_size-2, searched_sequence->getData(), searched_sequence->getDataLen()-1);
			
		if(score>min_score)
		{
			hasBeenFound = true;
	
			actual_offset=*(offset_header+i);
			header_size=*(offset_header+i+1)-actual_offset;	
			
			min = scores[0];
			short found=0;
			for(short j=0; j<RESULTS; j++)
			{
				if( !found && scores[j] == min_score )
				{
					found = 1;
					scores[j] = score;
					offsets[j] = actual_offset;
					sizes[j] = header_size;
				}
				if( scores[j] < min )
					min = scores[j];
			}
			min_score = min;
			
		}
		
		for (int i=0; i<=actual_size; i++)
			delete scoring_m[i];
		delete scoring_m;
		
	}
	
	
	delete read_data;
	
	return (void*) hasBeenFound;
}

bool DataBase::searchSequence(Sequence* searched_sequence)
{
        openDB(SEQUENCE);
	hasBeenFound = false;
	THREAD_COUNT=3;
	cout << "threads : " << THREAD_COUNT << endl;
	thread threads[THREAD_COUNT];
	
    	if(!is_open[SEQUENCE])
    	{
        	std::cout<<"DB couldn't be opened"<<std::endl;
        	return hasBeenFound;
    	}
    	
    	for (short i=0; i<THREAD_COUNT; i++)
    		threads[i] = thread(&DataBase::main_loop, this, searched_sequence, i);
    	//thread t0(&DataBase::main_loop, this, searched_sequence, 0);
    	
    	for (short i=0; i<THREAD_COUNT; i++)
    		threads[i].join();
	
    	
	if(!hasBeenFound)
	{
		std::cout<<"No equivalence founded to : -> "<<std::endl;
		//std::cout<<searched_sequence->getData()<<std::endl;
		closeDB(SEQUENCE);
	}
	else
	{	
		closeDB(SEQUENCE);
		openDB(HEADER);
			
		int max, highest_id;
		
		for (int i = 0; i<RESULTS; i++)
		{
			max = 0;
			for (int j = 0; j<RESULTS; j++)
			{
				if ( scores[j] > max )
				{
					max = scores[j];
					highest_id = j;
				}
			}
			
			cout << " score : " << scores[highest_id] << " - offset : " << offsets[highest_id] << " - size : " << sizes[highest_id] << endl;
			print_header( offsets[highest_id], sizes[highest_id]);
			scores[highest_id] = 0;
		}
		
		closeDB(HEADER);
		
	}
	
	return hasBeenFound;
}


