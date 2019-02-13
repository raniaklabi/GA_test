FOR %%i IN (1 2 3) DO (
FOR %%s IN (150) DO (
FOR %%t IN (30 50 70 100 120) DO (
DSCGAAvancer.exe %%i %%s %%t 10 1 500 200 5 exemple%%s_%%t_%%i.txt 10
)
)
)