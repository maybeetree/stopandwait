#/bin/sh

mkdir -p dat

echo "size, iters" > dat/e1.csv
for i in $(seq 0 20 1000)
do
	echo -n "${i}, " >> dat/e1.csv
	seq $i | shuf | ./snw 0 0 | wc -l >> dat/e1.csv
done

echo "p1, iters" > dat/e2.csv
for i in $(seq 0 0.01 1 | head -n -1)
do
	echo -n "${i}, " >> dat/e1.csv
	seq 200 | shuf | ./snw $i 0 | wc -l >> dat/e2.csv
done

echo "p, iters" > dat/e2.csv
for i in $(seq 0 0.01 1 | head -n -1)
do
	echo -n "${i}, " >> dat/e1.csv
	seq 100 | shuf | ./snw $i $i | wc -l >> dat/e3.csv
done

