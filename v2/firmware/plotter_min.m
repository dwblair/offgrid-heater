set datafile separator ","
set xlabel "minutes"
set ylabel "deg F"
plot "output.txt" using ($1/60):($3*9/5+32)
pause 5 
reread

