make
python3 analysis/random_generate.py > analysis/collision_input.txt
./rca < analysis/collision_input.txt | tee > analysis/collision_output.txt
cd analysis
python3 collision_analysis.py