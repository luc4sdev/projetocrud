
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Cria struct das disciplinas

 struct disciplinas {
    int id;
    char nome[100];
    int semestre;
    int ano;
};

// Cria struct para disciplinas a serem adicionadas

struct adicionardisciplina {
    char nome[100];
    int semestre;
    int ano;
};

// Cria struct para o endereco

struct enderecos {
    char rua[100];
    char bairro[100];
    int cep;
    char cidade[100];
    char uf[100];
    
};

// Cria struct dos alunos

struct alunos {
    int matricula;
    char nomecompleto[100];
    int idade;
    int quantidadedisciplinas;
    int iddisciplina[200];
    
    struct enderecos endereco;
};

// Cria struct dos alunos a serem adicionados

struct adicionaraluno {
    char nomecompleto[100];
    int idade;
    int quantidadedisciplinas;
    int iddisciplina[200];
    
    struct enderecos endereco;
};    
    
    // Funcao para verificar se existe um ID cadastrado no sistema
int VerificarID(int id) {
    
    struct disciplinas disciplina;
    FILE *disciplinasarq;
    disciplinasarq = fopen("disciplinas", "r+b");
        
        if(disciplinasarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
            
                // Verificar se o id da disciplina ja existe 
                
                int validardisc = 0;
                
                 if(fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq)!= 0) {
                     rewind(disciplinasarq);
                while(!feof(disciplinasarq) && validardisc == 0) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == id) {
                        validardisc = 1;
                    }
                }
                   
                }
                
                if(validardisc == 1) {
                        return 1;
                    }
                    return 0;
}     

// Funcao para inserir dosciplinas no arquivo

void InserirDisciplina() {
    struct disciplinas disciplina;
    int id;
    char nome[100];
    int semestre;
    int ano;
    int verificar;
    int i;
    
    // Abre o arquivo
    
    FILE *disciplinasarq;
    disciplinasarq = fopen("disciplinas", "ab");
        
        if(disciplinasarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
            
                // Verificar se o id da disciplina ja existe 
                
                printf("ID: ");
                scanf("%d", &id);
                
                if(VerificarID(id) == 1) {
                    printf("Ha uma disciplina cadastrada no sistema com esse ID.\n");
                        fclose(disciplinasarq);
                }
            
            else {
        
        printf("Nome: ");
        getchar();
        scanf("%[^\n]", nome);
        getchar();
        printf("Semestre: ");
        scanf("%d", &semestre);
        printf("Ano: ");
        scanf("%d", &ano);
        
        // Copia o valor das variaveis para a struct
        

                disciplina.id = id;
                strcpy(disciplina.nome, nome);
                disciplina.semestre = semestre;
                disciplina.ano = ano;
                
                
                
    // Inserir os valores da struct no arquivo            

    fwrite(&disciplina, sizeof(struct disciplinas), 1, disciplinasarq);
            
	// Fecha o arquivo
	fclose(disciplinasarq);
	printf("\n");
    printf("Disciplina inserida com sucesso!\n");
            }
}



// Funcao para Procurar disciplina no arquivo

void ProcurarDisciplina() {
    struct disciplinas disciplina;
    FILE *disciplinasarq;
    disciplinasarq = fopen("disciplinas", "r+b");
    
    if(disciplinasarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
        int id;
        printf("Digite o id da disciplina: ");
    scanf("%d", &id);
    
                int validardisc = 0;
                
                // Obter os dados da struct que esta armazenada no arquivo
                
                if(fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq)!= 1) {
                    printf("Nao ha disciplinas cadastradas no sistema!\n");
                }
                else {
                    rewind(disciplinasarq);
                }
                while(!feof(disciplinasarq) && validardisc == 0) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == id) {
                        
                        // Imprime os dados da disciplina na tela
                        
                        printf("\n");
                        printf("Dados da disciplina:\n");
                        printf("Id: %d\n", disciplina.id);
                        printf("Nome: %s\n", disciplina.nome);
                        printf("Ano: %d\n", disciplina.ano);
                        printf("Semestre: %d\n", disciplina.semestre);
                        validardisc = 1;
                    }
                    
                    
                }
                if(validardisc == 0) {
                        printf("ID nao encontrado no sistema.\n");
                        fclose(disciplinasarq);
                    }
                    
        else {
            fclose(disciplinasarq);
        }
    
}



void AlterarDisciplina() {
    
    struct disciplinas disciplina;
    struct adicionardisciplina adddisciplina;
    FILE *disciplinasarq;
    disciplinasarq = fopen("disciplinas", "r+b");
    
    if(disciplinasarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
    
    char nome[100];
    int semestre;
    int ano;
    int verificar;
    int i, id;
    
    
    printf("Digite o id da disciplina: ");
    scanf("%d", &id);
    
    
    
    int validardisc = 0;
                
                
                
                 if(fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq)!= 1) {
                    printf("Nao ha disciplinas cadastradas no sistema!\n");
                }
                else {
                    rewind(disciplinasarq);
                }
                while(!feof(disciplinasarq) && validardisc == 0) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == id) {
                        validardisc = 1;
                    }
                }
                if(validardisc == 0) {
                        printf("ID nao encontrado no sistema.\n");
                        fclose(disciplinasarq);
                    }
                    
                    else {
                    
        // Obtem os dados da disciplina a ser alterada
        
        printf("Atualizar dados:\n");
        printf("Nome: ");
        getchar();
        scanf("%[^\n]", nome);
        getchar();
        printf("Semestre: ");
        scanf("%d", &semestre);
        printf("Ano: ");
        scanf("%d", &ano);
   
   
    // Copia o valor das variaveis para a struct
        

                strcpy(adddisciplina.nome, nome);
                adddisciplina.semestre = semestre;
                adddisciplina.ano = ano;
                
                 validardisc = 0;
                
                
                // Copia os valores da struct para o local onde a disciplina esta armazenada no arquivo

                    rewind(disciplinasarq);
                    
                while(!feof(disciplinasarq) && validardisc == 0) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == id) {
                        
                        fseek(disciplinasarq, (sizeof(int) - sizeof(struct disciplinas)), SEEK_CUR);
                        fwrite(&adddisciplina, sizeof(struct adicionardisciplina), 1, disciplinasarq);
                        
                        validardisc = 1;
                    }
                    
                    
                }
                
                
    fclose(disciplinasarq);
    printf("\n");
    printf("Disciplina alterada com sucesso!\n");
                    }
    
}


void RemoverDisciplina() {
    struct disciplinas disciplina;
        
    FILE *disciplinasarq;
    disciplinasarq = fopen("disciplinas", "r+b");
    
    if(disciplinasarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
        
        int id;
        printf("Digite o ID da disciplina a ser removida: ");
        scanf("%d", &id);
        
        int validardisc = 0;
                
                // Verifica se o id da disciplina existe
                
                 if(fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq)!= 1) {
                    printf("Nao ha disciplinas cadastradas no sistema!\n");
                }
                else {
                    rewind(disciplinasarq);
                }
                while(!feof(disciplinasarq) && validardisc == 0) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == id) {
                        validardisc = 1;
                    }
                }
                if(validardisc == 0) {
                        printf("ID nao encontrado no sistema.\n");
                        fclose(disciplinasarq);
                        
                    }
                    
                    else {
                        
                        int validar = 0;
                
               
                    rewind(disciplinasarq);

                while(!feof(disciplinasarq) && validar == 0) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == id) {
                        
                        // Imprime os dados da disciplina na tela
                        
                        printf("\n");
                        printf("Dados da disciplina:\n");
                        printf("Id: %d\n", disciplina.id);
                        printf("Nome: %s\n", disciplina.nome);
                        printf("Ano: %d\n", disciplina.ano);
                        printf("Semestre: %d\n", disciplina.semestre);
                        validar = 1;
                    }
                    
                    
                }
                        int opcaodesejada;
                        printf("\n");
                        printf("\n");
                        printf("Tem certeza que deseja remover essa disciplina?\n");
                        printf("1 - SIM\n");
                        printf("2 - NAO\n");
                        printf("\n");
                        printf("Digite uma opcao: ");
                        scanf("%d", &opcaodesejada);
                        
                        if(opcaodesejada == 1) {
                    
                    // Cria um arquivo temporario para armazenar os dados do arquivo de disciplinas menos o que ira ser removido
                    
                    FILE *arqtemp;
    arqtemp = fopen("temporario", "w+b");
    if(arqtemp == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }


                    rewind(disciplinasarq);

                while(!feof(disciplinasarq)) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id != id) {
                        fwrite(&disciplina, sizeof(struct disciplinas), 1, arqtemp);
                    }
                }
                
                fclose(disciplinasarq);
                fclose(arqtemp);
                
                // Remove o arquivo das disciplinas e renomeia o arquivo temporario com o mesmo nome do arquivo das disciplinas
                
                remove("disciplinas");
                rename("temporario", "disciplinas");
                printf("Disciplina removida com sucesso!\n");
                        }
                        else {
                            fclose(disciplinasarq);
                        }
                    }
    
}



// Funcao para verificar se existe uma matricula cadastrado no sistema

int Verificarmatricula(int matricula) {
    
    struct alunos aluno;
    FILE *alunoarq;
    alunoarq = fopen("alunos", "r+b");
        
        if(alunoarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
            
                // Verificar se a matricula do aluno ja existe 
                
                int validaraluno = 0;
                
                 if(fread(&aluno, sizeof(struct alunos),1, alunoarq)!= 0) {
                     rewind(alunoarq);
                while(!feof(alunoarq) && validaraluno == 0) {
                    fread(&aluno, sizeof(struct alunos),1, alunoarq);
                    if(aluno.matricula == matricula) {
                        validaraluno = 1;
                    }
                }
                   
                }
                
                if(validaraluno == 1) {
                        return 1;
                    }
                    return 0;
}     


// Funcao para Inserir aluno no arquivo

void InserirAluno() {
    struct alunos aluno;
    struct enderecos endereco_aluno;
    
    int matricula;
    char nomecompleto[100];
    int idade;
    int iddisciplina[200];
    int verificar;
    char rua[100];
    char bairro[100];
    int cep;
    char cidade[100];
    char uf[100];
    
    int i;
    
    // Abre o arquivo
    
    FILE *alunoarq;
    alunoarq = fopen("alunos", "ab");
        
        if(alunoarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
            
        printf("Digite os dados do aluno:\n");
        printf("\n");
        printf("Matricula: ");
        scanf("%d", &matricula);
        
        if(Verificarmatricula(matricula) == 1) {
                    printf("Ha um(a) aluno(a) cadastrado(a) no sistema com essa matricula.\n");
                        fclose(alunoarq);
                }
                
                else {
        
        printf("Nome Completo: ");
        getchar();
        scanf("%[^\n]", nomecompleto);
        getchar();
        printf("Idade: ");
        scanf("%d", &idade);
        
        printf("Quantas disciplinas esta cursando: ");
        int quantidadedisciplinas;
        scanf("%d", &quantidadedisciplinas);
        int aux = quantidadedisciplinas;
        int j = 0;
        
        int contador = 1;
        while(quantidadedisciplinas--) {
        printf("ID da %dª disciplina: ", contador);
        scanf("%d", &iddisciplina[j]);
        contador++;
        j++;
        }
        
        printf("\n");
        
        
        printf("Endereco:\n");
        
        printf("Rua: ");
        getchar();
        scanf("%[^\n]", rua);
        getchar();
        printf("Bairro: ");
        scanf("%[^\n]", bairro);
        getchar();
        printf("CEP: ");
        scanf("%d", &cep);
        printf("Cidade: ");
        getchar();
        scanf("%[^\n]", cidade);
        getchar();
        printf("UF: ");
        scanf("%[^\n]", uf);
        getchar();
        
        
        int a;
        
        // Copia o valor das variaveis para a struct
        


                aluno.matricula = matricula;
                strcpy(aluno.nomecompleto, nomecompleto);
                aluno.idade = idade;
                aluno.quantidadedisciplinas = aux;
                for(a=0;a<aux;a++) {
                aluno.iddisciplina[a] = iddisciplina[a];
}
                strcpy(aluno.endereco.rua, rua);
                strcpy(aluno.endereco.bairro, bairro);
                aluno.endereco.cep = cep;
                strcpy(aluno.endereco.cidade, cidade);
                strcpy(aluno.endereco.uf, uf);
                
    
    // Copia o valor das variaveis da struct para o arquivo
    
    
    fwrite(&aluno, sizeof(struct alunos), 1, alunoarq);
    
            
			
		fclose(alunoarq);
		printf("\n");
    printf("Aluno inserido com sucesso!\n");
                }
}


void ProcurarAluno() {
    struct alunos aluno;
    FILE *alunoarq;
    alunoarq = fopen("alunos", "r+b");
    
    if(alunoarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
        int matricula;
        printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    
    
                 int validar = 0;
                
                // Obter os dados da struct que esta armazenada no arquivo
                
                if(fread(&aluno, sizeof(struct alunos),1, alunoarq)!= 1) {
                    printf("Nao ha alunos(as) cadastrados(as) no sistema!\n");
                }
                else {
                    rewind(alunoarq);
                }
                while(!feof(alunoarq) && validar == 0) {
                    fread(&aluno, sizeof(struct alunos),1, alunoarq);
                    if(aluno.matricula == matricula) {
                        
                        
                        printf("\n");
                        printf("Dados do(a) aluno(a):\n");
    

    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nomecompleto);
    printf("Idade: %d\n", aluno.idade);
    printf("Quantidade de disciplinas matriculadas: %d\n", aluno.quantidadedisciplinas);
    printf("\n");
    int i, auxiliarid;
    printf("Dados da(s) disciplina(s): \n");
    printf("\n");
    
    
        // Abrir o arquivo de disciplinas para inserir os dados das disciplinas do aluno

    struct disciplinas disciplina;
        
    FILE *disciplinasarq;
    disciplinasarq = fopen("disciplinas", "r+b");
    
    if(disciplinasarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
    
    for(i=0;i<aluno.quantidadedisciplinas;i++) {
    auxiliarid = aluno.iddisciplina[i];
        
        while(!feof(disciplinasarq)) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == auxiliarid) {
                        
                        printf("Dados da disciplina de ID(%d):\n", auxiliarid);
                        printf("Id: %d\n", disciplina.id);
                        printf("Nome: %s\n", disciplina.nome);
                        printf("Ano: %d\n", disciplina.ano);
                        printf("Semestre: %d\n", disciplina.semestre);
                        printf("\n");
                        break;
                    }
                }
                rewind(disciplinasarq);
    }
    
    fclose(disciplinasarq);
    
        printf("\n");
    printf("Endereco:\n");
    printf("Rua: %s\n", aluno.endereco.rua);
    printf("Bairro: %s\n", aluno.endereco.bairro);
    printf("CEP: %d\n", aluno.endereco.cep);
    printf("Cidade: %s\n", aluno.endereco.cidade);
    printf("UF: %s\n", aluno.endereco.uf);
        
    validar = 1;
                    }
                    
                    
                } 
                
                if(validar == 0) {
                        printf("Matricula nao encontrada no sistema.\n");
                        fclose(alunoarq);
                        
                    }
                    else {
                        fclose(alunoarq);
                    }
        
}


void AlterarAluno() {
    
    struct alunos aluno;
    struct adicionaraluno addaluno;
    FILE *alunoarq;
    alunoarq = fopen("alunos", "r+b");
    
    if(alunoarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
        
        char nomecompleto[100];
    int idade;
    int iddisciplina[200];
    int verificar;
    char rua[100];
    char bairro[100];
    int cep;
    char cidade[100];
    char uf[100];
        int matricula;
        
        
        printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    
     int validaraluno = 0;
                
                // Verifica se a matricula do aluno existe
                
                if(fread(&aluno, sizeof(struct alunos),1, alunoarq)!= 1) {
                    printf("Nao ha alunos(as) cadastrados(as) no sistema!\n");
                }
                else {
                    rewind(alunoarq);
                }
                while(!feof(alunoarq) && validaraluno == 0) {
                    fread(&aluno, sizeof(struct alunos),1, alunoarq);
                    if(aluno.matricula == matricula) {
                    validaraluno = 1;
                    break;
                    }
                } 
                
                if(validaraluno == 0) {
                        printf("Matricula nao encontrada no sistema.\n");
                        fclose(alunoarq);
                    }
    
    else {
    // Armazena os novos dados do aluno na struct
    
    printf("Digite os novos dados do aluno:\n");
        printf("\n");

        printf("Nome Completo: ");
        getchar();
        scanf("%[^\n]", nomecompleto);
        getchar();
        printf("Idade: ");
        scanf("%d", &idade);
        
        printf("Quantas disciplinas esta cursando: ");
        int quantidadedisciplinas;
        scanf("%d", &quantidadedisciplinas);
        int aux = quantidadedisciplinas;
        int j = 0;
        
        int contador = 1;
        while(quantidadedisciplinas--) {
        printf("ID da %dª disciplina: ", contador);
        scanf("%d", &iddisciplina[j]);
        contador++;
        j++;
        }
        
        printf("\n");
        
        
        printf("Endereco:\n");
        
        printf("Rua: ");
        getchar();
        scanf("%[^\n]", rua);
        getchar();
        printf("Bairro: ");
        scanf("%[^\n]", bairro);
        getchar();
        printf("CEP: ");
        scanf("%d", &cep);
        printf("Cidade: ");
        getchar();
        scanf("%[^\n]", cidade);
        getchar();
        printf("UF: ");
        scanf("%[^\n]", uf);
        getchar();
        
        
        int a;
        
        // Copia o valor das variaveis para a struct
        


                
                strcpy(addaluno.nomecompleto, nomecompleto);
                addaluno.idade = idade;
                addaluno.quantidadedisciplinas = aux;
                for(a=0;a<aux;a++) {
                addaluno.iddisciplina[a] = iddisciplina[a];
}
                strcpy(addaluno.endereco.rua, rua);
                strcpy(addaluno.endereco.bairro, bairro);
                addaluno.endereco.cep = cep;
                strcpy(addaluno.endereco.cidade, cidade);
                strcpy(addaluno.endereco.uf, uf);
                
    
      validaraluno = 0;
                
                // Armazena os novos dados do aluno no arquivo
                

                    rewind(alunoarq);

                while(!feof(alunoarq) && validaraluno == 0) {
                    fread(&aluno, sizeof(struct alunos),1, alunoarq);
                    if(aluno.matricula == matricula) {
                        
                        fseek(alunoarq, (sizeof(int) - sizeof(struct alunos)), SEEK_CUR);
                        fwrite(&addaluno, sizeof(struct adicionaraluno), 1, alunoarq);
                        
                     validaraluno = 1;
                    }
                    
                    
                } 
                    
                    fclose(alunoarq);
                    printf("\n");
    printf("Aluno alterado com sucesso!\n");
    }
}


void RemoverAluno() {
    struct alunos aluno;
        
    FILE *alunoarq;
    alunoarq = fopen("alunos", "r+b");
    
    if(alunoarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
        
        int matricula;
        printf("Digite a matricula do(a) aluno(a) a ser removido(a): ");
        scanf("%d", &matricula);
        
        int validaraluno = 0;
                
                 if(fread(&aluno, sizeof(struct alunos),1, alunoarq)!= 1) {
                    printf("Nao ha alunos(as) cadastrados(as) no sistema!\n");
                }
                else {
                    rewind(alunoarq);
                }
                while(!feof(alunoarq) && validaraluno == 0) {
                    fread(&aluno, sizeof(struct alunos),1, alunoarq);
                    if(aluno.matricula == matricula) {
                        validaraluno = 1;
                    }
                }
                if(validaraluno == 0) {
                        printf("Matricula nao encontrada no sistema.\n");
                        fclose(alunoarq);
                        
                    }
                    
                    else {
                        
                        int validar;
                        
                    rewind(alunoarq);

                while(!feof(alunoarq) && validar == 0) {
                    fread(&aluno, sizeof(struct alunos),1, alunoarq);
                    if(aluno.matricula == matricula) {
                        
                        
                        printf("\n");
                        printf("Dados do(a) aluno(a):\n");
    

    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nomecompleto);
    printf("Idade: %d\n", aluno.idade);
    printf("Quantidade de disciplinas matriculadas: %d\n", aluno.quantidadedisciplinas);
    printf("\n");
    int i, auxiliarid;
    printf("Dados da(s) disciplina(s): \n");
    printf("\n");
    
    
    
    struct disciplinas disciplina;
        
    FILE *disciplinasarq;
    disciplinasarq = fopen("disciplinas", "r+b");
    
    if(disciplinasarq == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
        
        
    for(i=0;i<aluno.quantidadedisciplinas;i++) {
    auxiliarid = aluno.iddisciplina[i];
    
        
        while(!feof(disciplinasarq)) {
                    fread(&disciplina, sizeof(struct disciplinas),1, disciplinasarq);
                    if(disciplina.id == auxiliarid) {
                        
                        printf("Dados da disciplina de ID(%d):\n", auxiliarid);
                        printf("Id: %d\n", disciplina.id);
                        printf("Nome: %s\n", disciplina.nome);
                        printf("Ano: %d\n", disciplina.ano);
                        printf("Semestre: %d\n", disciplina.semestre);
                        printf("\n");
                        break;
                    }
                }
                rewind(disciplinasarq);
    }
    
    fclose(disciplinasarq);
    
        printf("\n");
    printf("Endereco:\n");
    printf("Rua: %s\n", aluno.endereco.rua);
    printf("Bairro: %s\n", aluno.endereco.bairro);
    printf("CEP: %d\n", aluno.endereco.cep);
    printf("Cidade: %s\n", aluno.endereco.cidade);
    printf("UF: %s\n", aluno.endereco.uf);
        
    validar = 1;
                    }
                    
                    
                } 
                        
                    
                        
                        int opcaodesejada;
                        printf("\n");
                        printf("\n");
                        printf("Tem certeza que deseja remover esse(a) aluno(a)?\n");
                        printf("1 - SIM\n");
                        printf("2 - NAO\n");
                        printf("\n");
                        printf("Digite uma opcao: ");
                        scanf("%d", &opcaodesejada);
                        
                    if(opcaodesejada == 1) {
        // Cria um arquivo temporario
        
        FILE *arqtempalu;
    arqtempalu = fopen("temporarioalunos", "w+b");
    if(arqtempalu == NULL) {
            printf("Erro na abertura\n");
            system("pause");
            exit(1);
        }
        
        
        
        // Copia os dados do arquivo de alunos para o arquivo temporario exceto os dados que quer remover
        
                    rewind(alunoarq);
                    
                while(!feof(alunoarq)) {
                    fread(&aluno, sizeof(struct alunos),1, alunoarq);
                    if(aluno.matricula != matricula) {
                        fwrite(&aluno, sizeof(struct alunos), 1, arqtempalu);
                    }
                }
                
                fclose(alunoarq);
                fclose(arqtempalu);
                
                // Apaga o arquivo de alunos e renomeia o arquivo temporario com o mesmo nome do arquivo de alunos
                
                remove("alunos");
                rename("temporarioalunos", "alunos");
                printf("Aluno(a) removido(a) com sucesso!\n");
                    }
                    else {
                        fclose(alunoarq);
                    }
                    }
}


int main()
{
    // MENU PRINCIPAL
    int opcao;
    do {
    printf("Sistema de Gestao de Cadastro de Alunos -> INF - UFG\n");
    
    printf("\n");
    
    printf("-------------------- MENU --------------------\n");
    
    printf("\n");
    printf("\n");
    
    printf("1 - Gerenciar disciplinas\n");
    
    printf("2 - Gerenciar alunos\n");
    
    printf("0 - Sair\n");
    
    printf("\n");
    
    printf("Digite uma opcao: ");
    
    
    
    scanf("%d", &opcao);
    system("cls");
   
    
    
    // MENU DISCIPLINA
        
    if(opcao == 1) {
        int opcaodisciplina;
        
        do {
    printf("-------------------- MENU DISCIPLINAS --------------------\n");
    
    printf("1 - Inserir nova disciplina\n");
    
    printf("2 - Pesquisar disciplina\n");
    
    printf("3 - Atualizar dados de uma disciplina\n");
    
    printf("4 - Remover uma disciplina\n");
    
    printf("0 - Sair\n");
    
    printf("\n");
    
     printf("Digite uma opcao: ");
    
    
    scanf("%d", &opcaodisciplina);
    
    system("cls");
    int opcaovoltar;
    if(opcaodisciplina == 1) {
        
        InserirDisciplina();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaovoltar);
    }
    
    else if(opcaodisciplina == 2) {
        ProcurarDisciplina();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaovoltar);
    }
    
    else if(opcaodisciplina == 3) {
        AlterarDisciplina();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaovoltar);
    }
    
    else if(opcaodisciplina == 4) {
        RemoverDisciplina();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaovoltar);
    }
    system("cls");
}while(opcaodisciplina != 0);
}
    // MENU ALUNO

    else if(opcao == 2) {
        int opcaoaluno;
        do {
    printf("-------------------- MENU ALUNOS --------------------\n");
            
    printf("1 - Inserir aluno(a)\n");
    
    printf("2 - Pesquisar aluno(a)\n");
    
    printf("3 - Atualizar dados de um(a) aluno(a)\n");
    
    printf("4 - Remover um(a) aluno(a)\n");
    
    printf("0 - Sair\n");
    
    printf("\n");
    
     printf("Digite uma opcao: ");
    
    
    scanf("%d", &opcaoaluno);
    
    system("cls");
        
        int opcaoalunovoltar;
        if(opcaoaluno == 1) {
        
        InserirAluno();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaoalunovoltar);
    }
    
    else if(opcaoaluno == 2) {
        
        ProcurarAluno();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaoalunovoltar);
    }
    
    else if(opcaoaluno == 3) {
        
        AlterarAluno();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaoalunovoltar);
    }
    
    else if(opcaoaluno == 4) {
        
        RemoverAluno();
        printf("\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaoalunovoltar);
    }
    system("cls");
        }while(opcaoaluno != 0);
}


    if(opcao == 0) {
        exit(1);
    }
 }while(opcao != 0);

    return 0;
}
