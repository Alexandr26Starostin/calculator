#ifndef GRAMMAR_H
#define GRAMMAR_H

calculate_error_t get_g (char* str, size_t* ptr_index, double* ptr_value);
calculate_error_t get_t (char* str, size_t* ptr_index, double* ptr_value); 
calculate_error_t get_e (char* str, size_t* ptr_index, double* ptr_value); 
calculate_error_t get_n (char* str, size_t* ptr_index, double* ptr_value); 

#endif