#include <iostream>
#include <vector>
#include <math.h>

std::vector <std::vector <double>> inv_matr(int n, std::vector <std::vector<double>> matr);
std::vector <std::vector <double>> mult_matr(int n, std::vector <std::vector<double>> matr1, std::vector <std::vector<double>> matr2);

int main(int argc, char* argv[]){
	
	int i, j, n, k, default_value;	
	
	default_value = 0.0;
	n = 3;
	k = 1;
	
	std::vector <std::vector<double>> matr(n, std::vector<double>(n, default_value));
	std::vector <std::vector<double>> rmatr(n, std::vector<double>(n, default_value));
	std::vector <std::vector<double>> multMatr(n, std::vector<double>(n, default_value));
	
	try{
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				matr[i][j] = std::stod(argv[k]);
				k++;
			}	
		}
	}
	catch(...){
		std::cout << "Not able to parse arguments" << std::endl;
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			std::cout << matr[i][j] << " ";
		}	
		std::cout << std::endl;
	}
	std::cout << std::endl;

	rmatr = inv_matr(n, matr);
	multMatr = mult_matr(n, matr, rmatr);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			std::cout << multMatr[i][j] << " ";
		}	
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}

std::vector <std::vector <double>> inv_matr(int n, std::vector <std::vector<double>> matr){
	
	int i, j, m, max_i;
	double max_a, b, del,default_value;
	default_value = 0.0;
	std::vector <std::vector<double>> ematr(n, std::vector<double>(n, default_value));
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == j)ematr[i][j] = 1;
			else ematr[i][j] = 0;
		}	
	}
	
	for(int k = 0; k < n; k++){
		for(int l = 0; l < n; l++)std::cout << matr[k][l] << " ";
		std::cout << "\t|";
		for(int l = 0; l < n; l++)std::cout << ematr[k][l] << " ";	
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for(m = 0; m < n - 1; m++){
		
		std::cout << "shaq = " << m << std::endl;
		
		max_a = matr[m][m];
		
		for(i = m + 1; i < n; i++){
			if(fabs(max_a) < fabs(matr[i][m])){max_i = i; max_a = matr[i][m];}
		}
		
		std::cout << "max = " << max_a << " m = " << m << " max_i = " << max_i << std::endl;
		if(max_i != m){
			for(j = 0; j < n; j++){
				b = matr[m][j]; matr[m][j] = matr[max_i][j]; matr[max_i][j] = b;
				b = ematr[m][j]; ematr[m][j] = ematr[max_i][j]; ematr[max_i][j] = b;
			}
		}
		
		for(int k = 0; k < n; k++){
			for(int l = 0; l < n; l++)std::cout << matr[k][l] << " ";
			std::cout << "\t|";
			for(int l = 0; l < n; l++)std::cout << ematr[k][l] << " ";	
			std::cout << std::endl;
		}
		std::cout << std::endl;
		
		for(i = m + 1; i < n; i++){
			del = matr[i][m]/matr[m][m];
			for(j = 0; j < n; j++){
				matr[i][j] -= del*matr[m][j];
				ematr[i][j] -= del*ematr[m][j];
			}
		}
		 
		for(int k = 0; k < n; k++){
			for(int l = 0; l < n; l++)std::cout << matr[k][l] << " ";
			std::cout << "\t|";
			for(int l = 0; l < n; l++)std::cout << ematr[k][l] << " ";	
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	
	
	for(int k = 0; k < n; k++){
		for(int l = 0; l < n; l++)std::cout << matr[k][l] << " ";
		std::cout << "\t|";
		for(int l = 0; l < n; l++)std::cout << ematr[k][l] << " ";	
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	
	
	
	for(i = 0; i < n; i++){
		del = matr[i][i];
		for(j = 0; j < n; j++){
			matr[i][j] /= del;
			ematr[i][j] /= del;
		}
	}
		
	for(m = n - 1; m > 0; m--){
		for(i = 0; i < m; i++){
			del = matr[i][m]/matr[m][m];
			for(j = 0; j < n; j++){
				matr[i][j] -= del*matr[m][j];
				ematr[i][j] -= del*ematr[m][j];
			}
		}
	}
	
	
	for(i = 0; i < n; i++){
		del = matr[i][i];
		for(j = 0; j < n; j++){
			matr[i][j] /= del;
			ematr[i][j] /= del;
		}
	}
	
	return ematr;
}

std::vector <std::vector <double>> mult_matr(int n, std::vector <std::vector<double>> matr1, std::vector <std::vector<double>> matr2){
	int i, j, k;
	double default_value = 0.0;
	std::vector <std::vector<double>> mult_matrix(n, std::vector<double>(n, default_value));
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < n; k++)mult_matrix[i][j] += matr1[i][k]*matr2[k][j];
		}
	}
	return mult_matrix;
}




