FOR %%i IN (1 2 3) DO (
FOR %%s IN (150) DO (
FOR %%t IN (30 50 70 100 120) DO (
FOR %%j IN (1 2 3 4 5 6 7 8 9 10) DO (
DSCGAAvancer.exe %%i %%s %%t 10 1 500 200 5 Exemple%%s_%%t_%%i_%%j.txt 
)
)
)
)