# Makefile whos function is to clean all for each java matrix multiplication

.PHONY: clean_all

clean_all:
	@cd 128_Quick_Basic_Java_Imp && make clean
	@cd Adv_Java_Imp_Library && make clean
	@cd Adv_Java_Imp_Multithreading && make clean
	@cd Basic_Java_Imp && make clean

