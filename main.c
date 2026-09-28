#include <stdio.h>
#include <stdlib.h>

// Modulo auxiliar para pausar a tela
void freeze() {
    printf("\n(Pressione ENTER para continuar)");
    getchar();
    getchar();
}

// Modulo que printa textos cinzas
void printcinza(char text[]){
	printf("\033[2m%s\033[0m",text);
}

// Modulo auxiliar para escolher um dos dois vetores
void selecionar(int v1[],int v2[],int M, int N,int vs[],int *vs_size){
	int e = 0;
	//Seleciona automaticamente se somente um vetor foi digitado
	if(M > 0 && N <=0){
		printf("\nVetor 1 selecionado\n");
		e = 1;
	}
	if(N > 0 && M <=0){
		printf("\nVetor 2 selecionado\n");
		e = 2;
	}
	
	//Se os 2 vetores foram digitados pede para o usuario escolher um dos dois
	if(e==0){
		printf("\nSelecione o Vetor que sera utilizado:\n");
		printf("1- Vetor 1\n");
		printf("2- Vetor 2\n");
		scanf("%d",&e);
		while(e != 1 && e != 2){
			printf("Erro!! valor invalido \nEscolha o Vetor(digite 1 ou 2): ");
			scanf("%d",&e);
		}
	}
	
	//Armazena os valores do vetor escolhido em um novo vetor
	if(e==1){
		*vs_size = M;
		for(int i=0;i<M;i++){
			vs[i] = v1[i];
		}
	} else if(e==2){
		*vs_size = N;
		for(int i=0;i<N;i++){
			vs[i] = v2[i];
		}
	}
	
}

// Função para obter o tamanho/limite de um vetor (OBS 3 e 4)
int get_limite(int max_size) {
    int q = 0;
    printf("Digite a quantidade de elementos do vetor (0 < Q <= %d): ", max_size);
    scanf("%d", &q);
    //Enquanto o valor não estiver dentro do limite pede para digitar novamente
    while (q <= 0 || q > max_size) {
        printf("Erro! Valor invalido. Digite um valor entre 1 e %d: ", max_size);
        scanf("%d", &q);
    }
    return q;
}

// Função para obter o escalar (OBS 5)
int obter_escalar() {
    int escalar;
    printf("Digite o valor do escalar (numero inteiro): ");
    scanf("%d", &escalar);
    return escalar;
}

// Função que verifica se o vetor esta ordenado
int vetor_ordenado(int vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (vet[i] > vet[i + 1]) {
            return 0;
        }
    }
    return 1;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// REQUISITO 1: Obter quantidade M (M <= 30) de elementos do primeiro vetor
void obter_primeiro_vetor(int vet[], int *M) {
	
    *M = get_limite(30); //Obtem quantidade de elementos do vetor com uma função(OBS 3)
    
    printf("Digite os %d elementos do primeiro vetor:\n", *M);
    //Lê os elementos do vetor
    for (int i = 0; i < *M; i++) {
        printf("[%d]: ", i+1);
        scanf("%d", &vet[i]);
    }
}

// REQUISITO 2: Obter quantidade N (N <= 20) de elementos do segundo vetor
void obter_segundo_vetor(int vet[], int *N) {
	
    *N = get_limite(20); //Obtem quantidade de elementos do vetor com uma função(OBS 4)
    
    printf("Digite os %d elementos do segundo vetor:\n", *N);
    //Lê os elementos do vetor
    for (int i = 0; i < *N; i++) {
        printf("[%d]: ", i+1);
        scanf("%d", &vet[i]);
    }
}

// REQUISITO 3: Listar os elementos de um vetor
void listar_vetor(int vet[], int tam) {
	//Apenas lista um vetor (OBS 2)
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// REQUISITO 4: Gerar vetor por adição dos elementos correspondentes de dois vetores
void somar_vetores(int v1[], int v2[], int v_res[], int tam) {
	//Apenas soma dois vetores (OBS 2)
    for (int i = 0; i < tam; i++) {
        v_res[i] = v1[i] + v2[i];
    }
}

// REQUISITO 5: Gerar vetor pela multiplicação de um escalar por um vetor
void multiplicar_por_escalar(int v_origem[], int v_resultado[], int tam) {
	
    int escalar = obter_escalar(); //Obtem o escalar com uma função(OBS 5)
    //Multiplica o vetor pelo escalar
    for (int i = 0; i < tam; i++) {
        v_resultado[i] = v_origem[i] * escalar;
    }
}

// REQUISITO 6: Pesquisar se um número existe em um vetor
int pesquisar_elemento(int vet[],int tam,int num) {
	//Apenas pesquisa se o numero existe em um vetor(OBS 2)
    for (int i = 0; i < tam; i++) { //Percorre o vetor
        if (vet[i] == num) { // Quando encontar o numero retorna 1
            return 1;
        }
    }
    //Se nao encontrar retorna 0
    return 0;
}

// REQUISITO 7: Gerar vetor com elementos exclusivos (diferença simétrica)
void elementos_exclusivos(int v1[],int v2[],int M,int N,int v_res[],int *t_res) {
	int tam = 0,achou = 0;
    
    // Elementos do v1 que não estão em v2
    for (int i = 0; i < M; i++) {		//Percorre o v1 (v[i]=elemento que sera verificado)
    	achou=0;//variavel de apoio
        for (int j = 0; j < N; j++) {		//Percorre o v2 (v[j]=elemento que sera comparado ao v[i])
            if (v1[i] == v2[j]) {		//Quando encontrar um valor de v1 igual a v2 muda a variavel de apoio e para de percorrer o v2
                achou = 1;
                break;
            }
    	}
    	if(achou == 0){			//Se a variavel de apoio nao foi mudada esse elemento do v1 não esta no v2
    		v_res[tam] = v1[i];//Adiciona o elemento ao vetor resultante
            tam++;
		}
    }
    // Elementos do v2 que não estão em v1 (Mesma lógica do de cima)
    for (int i = 0; i < N; i++) {
    	achou=0;
        for (int j = 0; j < M; j++) {
            if (v2[i] == v1[j]) {
            	achou = 1;
                break;
            }
        }
        if(achou == 0){
			v_res[tam] = v2[i];
            tam++;
		}
    }
    
    *t_res = tam;
}

// REQUISITO 8: Intercalação de dois vetores ordenados mantendo a ordenação
void intercalar_vetores_ordenados(int v1[],int v2[],int M,int N,int v_intercalado[],int *t_res) {
    int i = 0, j = 0, k = 0;

    // Algoritmo de intercalação (Merge)
    while (i < M && j < N) {
        if (v1[i] <= v2[j]) {
            v_intercalado[k] = v1[i];
            i++;
        } else {
            v_intercalado[k] = v2[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de v1, se houver
    while (i < M) {
        v_intercalado[k] = v1[i];
        k++;
        i++;
    }

    // Copia os elementos restantes de v2, se houver
    while (j < N) {
        v_intercalado[k] = v2[j];
        k++;
        j++;
    }
    *t_res=k;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


// Função Principal
int main() {
    int v1[30], v2[20], v_resultado[50],v_selecionado[30];
    int M = 0, N = 0, tam_resultado = 0,vs_size = 0;
    int num;
    int opcao = -1;

    while (opcao != 9) {
    	////////////////
    	//Exibe o menu//
    	////////////////
        printf("\n==================== MENU ====================\n");
        
        //Primeira opção
        if(M==0){			//Muda de criar para editar para indicar que o vetor ja foi criado
        	printf("1) Criar primeiro vetor (M <= 30)\n");
		}else{
			printf("1) Editar primeiro vetor (M <= 30)\n");
		}
		
		//Segunda opção
        if(N==0){			//Muda de criar para editar para indicar que o vetor ja foi criado
        	printf("2) Criar segundo vetor (N <= 20)\n");
		}else{
			printf("2) Editar segundo vetor (N <= 20)\n");
		}
		
		//Terceira opção
		if(M!=0||N!=0){			//Muda a cor do texto quando nao existe nenhum vetor pra indicar que essa opção não ira funcionar
			printf("3) Listar vetores armazenados\n");
		}else{
			printcinza("3) Listar vetores armazenados\n");
		}
		
        //Quarta opção
        if(M==N && M!=0){		//Muda a cor do texto quando os vetores não tem tamanhos iguais ou não existem pra indicar que essa opção não ira funcionar
       		printf("4) Somar primeiro e segundo vetor\n");	
		}else{
			printcinza("4) Somar primeiro e segundo vetor\n");
		}
		
        //Quinta e Sexta opção
        if(M!=0||N!=0){			//Muda a cor do texto quando nao existe nenhum vetor pra indicar que essa opção não ira funcionar
        	printf("5) Multiplicar vetor por um escalar\n");
        	printf("6) Pesquisar elemento em um vetor\n");
		}else{
			printcinza("5) Multiplicar vetor por um escalar\n");
			printcinza("6) Pesquisar elemento em um vetor\n");
		}
		//Setima opção
		if(M!=0&&N!=0){			//Muda a cor do texto quando os dois vetores não foram criados pra indicar que essa opção não ira funcionar
			printf("7) Gerar vetor com elementos exclusivos de dois vetores\n");
		}else{
			printcinza("7) Gerar vetor com elementos exclusivos de dois vetores\n");
		}
        //Oitava opção
        if(M!=0&&N!=0&&vetor_ordenado(v1,M)==1 && vetor_ordenado(v2,N)==1){			//Muda a cor do texto quando os dois vetores não estiverem ordenados ou não foram criados pra indicar que essa opção não ira funcionar
			printf("8) Intercalar dois vetores ordenados\n");
		}else{
			printcinza("8) Intercalar dois vetores ordenados\n");
		}
		//Nona opção
        printf("9) Finalizar execucao\n");
        
        printf("==============================================\n");
        printf("Escolha uma opcao (1-9): ");
        scanf("%d", &opcao);
        
        
        
        ///////////////////////////
        //Parte funcional do Menu//
        ///////////////////////////
        switch (opcao) {
            case 1: //Obtem primeiro Vetor (REQUISITO 1)
                obter_primeiro_vetor(v1, &M);
                break;
                
            case 2: //Obtem segundo Vetor (REQUISITO 2)
                obter_segundo_vetor(v2, &N);
                break;
                
            case 3: //Lista os elementos de um vetor (REQUISITO 3)
            
            	if(M>0){ //Só lista o primeiro se ele existir
            		printf("\nPrimeiro Vetor (tamanho %d):\n", M);
                	listar_vetor(v1, M);
				}
                if(N>0){ //Só lista o segundo se ele existir
                	printf("\nSegundo Vetor (tamanho %d):\n", N);
                	listar_vetor(v2, N);
				}
                
                if (tam_resultado > 0) { //Só lista o vetor gerado se ele existir
                    printf("\nUltimo Vetor Gerado (tamanho %d):\n", tam_resultado);
                    listar_vetor(v_resultado, tam_resultado);
                }
                
                if(M==0&&N==0){ //Se nenhum vetor foi criado exibe erro
                	printf("\nErro: Nenhum vetor foi criado\n");
				}
                freeze();
                break;
                
            case 4: //Soma dois vetores (Requisito 4)
            
                if (M <= 0 || N <= 0) { // Só soma os vetores se eles existirem
                    printf("\nErro: Ambos os vetores (1 e 2) precisam ser informados primeiro!\n");
                } else if (M != N) { // Só soma os vetores se eles forem iguais
                    printf("\nErro: Para somar, os vetores precisam ter o mesmo tamanho (M = %d, N = %d)!\n", M, N);
                } else { // Soma os vetores
                    somar_vetores(v1, v2, v_resultado, M);
                    tam_resultado = M;
                    printf("\nVetor criado com sucesso!!\n");
                }
                freeze();
                break;
                
            case 5: //Gera um vetor apartir de outro vetor multiplicado por um escalar (Requisito 5)
                if (M <= 0 && N <= 0) {//Só gera se um vetor ja foi criado
                    printf("\nErro: Nenhum vetor informado!!\n");
                } else {//Gera o vetor...
                	selecionar(v1,v2,M,N,v_selecionado,&vs_size);
                    multiplicar_por_escalar(v_selecionado, v_resultado, vs_size);
                    tam_resultado = vs_size;
                    printf("\nVetor criado com sucesso!!\n");
                }
                freeze();
                break;
                
            case 6: //Pesquisa se um número existe ou não em um vetor (Requisito 6)
            	if (M <= 0 && N <= 0) {//Só pesquisa se um vetor ja foi criado
                    printf("\nErro: Nenhum vetor informado!!\n");
                } else {//Pesquisa...
                	selecionar(v1,v2,M,N,v_selecionado,&vs_size);
            		printf("Digite o numero a ser pesquisado: ");
					scanf("%d", &num);
               		if (pesquisar_elemento(v_selecionado,vs_size,num)==1) {
						printf("O numero %d EXISTE no vetor.\n", num);
    				} else {
        				printf("O numero %d NAO EXISTE no vetor.\n", num);
    				}	
                }
				freeze();
                break;
            case 7: //Gera um vetor que possui os elementos que existem apenas em um dos dois vetores (Requisito 7)
            	if(M==0||N==0){ //Só gera se tiver os 2 vetores
            		printf("\nErro: Os vetores 1 e 2 precisam ser informados primeiro!\n");
				}else{//Gera o vetor...
					elementos_exclusivos(v1,v2,M,N,v_resultado,&tam_resultado);
					printf("\nVetor criado com sucesso!!\n");
				}
                freeze();
                break;
                
            case 8: //Gera um vetor apartir da intercalação de 2 vetores ordenados (Requisito 8)
            	if(M==0||N==0){ //Só gera se tiver os 2 vetores
            		printf("\nErro: Os vetores 1 e 2 precisam ser informados primeiro!\n");
				}else if(vetor_ordenado(v1,M)==0 || vetor_ordenado(v2,N)==0){  //Só gera o vetor se os dois vetores estiverem ordenados(OBS contida no REQUISITO 8)
					printf("\nErro: Os vetores precisam estar ordenados!!(ex: v1: 2 4 6 / v2: 1 3 5)\n");
				}else{ //Gera o vetor...
					intercalar_vetores_ordenados(v1,v2,M,N,v_resultado,&tam_resultado);
                	printf("\nVetor criado com sucesso!!\n");
				}
                freeze();
                break;
            case 9: //Finaliza o programa (Requisito 9)
                printf("\nPrograma finalizado com sucesso.\n");
                //Como o valor é 9 sai do while e finaliza o programa
                break;
                
            default: //Caso usuario digite uma opção invalida exibe erro
                printf("\nOpcao invalida! Tente novamente.\n");
                freeze();
                break;
        }
    }

    return 0;
}
