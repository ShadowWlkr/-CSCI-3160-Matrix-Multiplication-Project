.PHONY: test clean

# Used to run matrix mult and output on screen data to txt file for later usage if needed
test:
	@java Java_Adv_Imp_Multithreading.java | tee Adv_Java_Imp_Multithreading_Benchmark.txt

# Used to clean all data once examined for correctness
clean:
	@rm -rf 128 256 512 Adv_Java_Imp_Multithreading_Benchmark.txt
