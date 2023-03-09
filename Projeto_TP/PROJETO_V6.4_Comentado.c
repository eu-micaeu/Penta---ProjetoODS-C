#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Bloco de Definicao de Estruturas*/
typedef struct e{//Estrututura de endereços
    char nome_cidade[20];
    int numero;
    char rua[20];
    char bairro[20];
	}local;
typedef struct p//Estrutura de Paciente
{
    char nome_paciente[20];		
    char sobrenome_paciente[20];
    char data_de_nascimento[11];
    char email[40];
    char senha[40];
    char cpf[40];
    char telefone_paciente[12];
    int numero_de_enderecos;
}paciente;
typedef struct m //Estrutura de Medico
{
    char nome_medico[20];
    int crm;
    char especialidade[40];
    char disponibilidade_na_semana[11];
    char disponibilidade_hora[6];
    char email[40];
    char senha[40];
    int numero_de_hospitais;
}medico;
/*Fim do Bloco de Definicao de Estruturas*/

/*Bloco de Prototipos de Funcoes*/
int cadastro(medico *medico, paciente *usuario, local *endereco); 					//Uma Funcao para cadastro de dados utilizando registro e alocacao dinamica de memoria
void apresentar_cadastro(int op, medico *medico, paciente *usuario); 				//Uma Funcao para apresentacao dos dados cadastrados / Uma Funcao com passagem por valor
void calculo_risco_cardiovascular();												//Uma Funcao para calcular o risco cardiovascular
void pontuacao_homens(int *pontos, float *risco); 									//Uma Funcao que utilize ponteiros para mostrar o risco cardiovascular Meminino
void pontuacao_mulheres(int *pontos, float *risco);									//Uma Funcao que utilize ponteiros para mostrar o risco cardiovascular Feminino
void buscar_hospitais(); 															//Uma Funcao para buscar dados 
void buscar_remedio(medico *medico); 												//Uma Funcao utilizando referência / Uma Funcao para buscar dados 
/*Fim do Bloco de Prototipos de Funcoes*/

void main(){																		//Funcao Main
   	medico medico;																	//Declaracao Estrutura Medico
    paciente usuario;																//Declaracao Estrutura Paciente
    local endereco;																	//Declaracao Estrutura Local
    setlocale(LC_ALL, "Portuguese");												//Nos permite usar o alfabeto Portugues com seus caracteres especiais como acentos e cedilhas 
    int opcao_escolhida = cadastro(&medico, &usuario, &endereco);					//Atribuicao do resultado da funcao cadastro, que tem como retorno opcao medico ou paciente
    apresentar_cadastro(opcao_escolhida, &medico, &usuario);						//Mostra o Cadastro que acabou de ser feito
    opcao_escolhida == 1 ? buscar_remedio(&medico) : printf("\n");
    opcao_escolhida == 2 ? buscar_hospitais() : printf("\n");
}

int cadastro(medico *medico, paciente *usuario, local *endereco){//Funcao de Cadastro
    /*Bloco de Declaracoes*/
	int op, i;
	/*FIM do bloco de Declaracoes*/
    printf("\nPara seguir com o nosso cadastro, selecione:\n\n1 - Medico\n2 - Paciente\n\n--> ");
    scanf("%d", &op);
    switch (op){
        
        case 1: 
        	/*Cadastro de Medico*/
            printf("\nNome do Medico: ");
            scanf("%s", medico->nome_medico);									//Nome
            printf("\nCRM do Medico: ");
            scanf("%d", &medico->crm);											//CRM
            printf("\nEspecialidade do Medico: ");
            scanf("%s", medico->especialidade);									//Especialidade
            printf("\nDisponibilidade da semana do Medico: ");
            scanf("%s", medico->disponibilidade_na_semana);						//Disponibilidade(Dias da Semana)
            printf("\nDisponibilidade da hora do Medico: ");
            scanf("%s", medico->disponibilidade_hora);							//Disponibilidade(Horarios)
            printf("\nEmail do Medico: ");
            scanf("%s", medico->email);											//Email
            printf("\nSenha do Medico: ");
            scanf("%s", medico->senha);											//Senha do Medico
            printf("\nTrabalha em quantos hospitais? (Maximo de 3): ");
            scanf("%d", &medico->numero_de_hospitais);							//Numero de Hospitais trabalhados
            endereco =  malloc(medico->numero_de_hospitais * sizeof(local));
            for (i = 0; i < medico->numero_de_hospitais; i++){					//Loop para cadastro dos esdere�os dos possiveis hospitais trabalhados
                printf("\nNome da Cidade do Hospital %d: ", i + 1);
                scanf("%s", endereco[i].nome_cidade);							//Nome da Cidade
                printf("\nNumero do Endereco do Hospital %d: ", i + 1);
                scanf("%d", &endereco[i].numero);								//Numero do endereco
                printf("\nRua do Endereco do Hospital %d: ", i + 1);
                scanf("%s", endereco[i].rua);									//Rua
                printf("\nBairro do Endereco do Hospital %d: ", i + 1);
                scanf("%s", endereco[i].bairro);								//Bairro
            }
            printf("\nCADASTRO REALIZADO\n");
            free(endereco);
            break; 

        case 2: 
        	/*Cadastro de Paciente*/
            printf("\nNome do Paciente: ");
            scanf("%s", usuario->nome_paciente);								//Nome do Paciente
            printf("\nSobrenome do Paciente: ");
            scanf("%s", usuario->sobrenome_paciente);							//Sobrenome do Paciente
            printf("\nData de Nascimento do Paciente: ");
            scanf("%s", usuario->data_de_nascimento);							//Data de Nascimento
            printf("\nCPF do Paciente: ");
            scanf("%s", usuario->cpf);											//CPF
            printf("\nTelefone do Paciente: ");
            scanf("%s", usuario->telefone_paciente);							//Telefone
            printf("\nEmail do Paciente: ");
            scanf("%s", usuario->email);										//Email
            printf("\nSenha do Paciente: ");
            scanf("%s", usuario->senha);										//Senha do Paciente
            printf("\nPossui quantos enderecos? ");
            scanf("%d", &usuario->numero_de_enderecos);							//Numero de Enderecos Possiveis
            endereco =  malloc(usuario->numero_de_enderecos * sizeof(local));
            for (i = 0; i < usuario->numero_de_enderecos; i++){					//Loop para cadastro dos enderecos de moradia do paciente
                printf("\nNome da Cidade do Endereço %d: ", i + 1);
                scanf("%s", endereco[i].nome_cidade);							//Nome da Cidade
                printf("\nNumero do Endereco %d: ", i + 1);
                scanf("%d", &endereco[i].numero);								//Numero do endereco
                printf("\nRua do Endereco %d: ", i + 1);
                scanf("%s", endereco[i].rua);									//Rua
                printf("\nBairro do Endereco %d: ", i + 1);
                scanf("%s", endereco[i].bairro);								//Bairro
            }
            printf("\nCADASTRO REALIZADO\n");
            free(endereco);
            break;
    } 
    return op;
}
void apresentar_cadastro(int op, medico *medico, paciente *usuario){//Funcao que Apenas mostra os dados do cadastro
    printf("----------------------------------\n");
    printf("\nApresentando o cadastro realizado:\n");
    switch (op){
        case 1: 
        	/*Medico*/
            printf("\nNome do Medico: %s", medico->nome_medico);										//Nome
            printf("\nCRM do Medico: %d",medico->crm);													//CRM
            printf("\nEspecialidade do Medico: %s", medico->especialidade);								//Especialidade
            printf("\nDisponibilidade da semana do Medico: %s", medico->disponibilidade_na_semana);		//Disponibilidade(Dias da Semana)
            printf("\nDisponibilidade da hora do Medico: %s", medico->disponibilidade_hora);			//Disponibilidade(horas)
            
            break; 
        case 2: 
            /*Paciente*/
			printf("\nNome do Paciente: %s", usuario->nome_paciente);									//Nome
            printf("\nSobrenome do Paciente: %s", usuario->sobrenome_paciente);							//Sobrenome
            printf("\nData de Nascimento do Paciente: %s", usuario->data_de_nascimento);				//Data de Nascimento
            printf("\nCPF do Paciente: %s", usuario->cpf);												//CPF
            printf("\nTelefone do Paciente: %s", usuario->telefone_paciente);							//TElefone
            printf("\nQuantidade de endereços: %d", usuario->numero_de_enderecos);						//Numero de enderecos
            printf("\n----------------------------------\n");
            calculo_risco_cardiovascular();																//Chamada da funcao de calculo do risco vascular
            break;
    } 
}
void pontuacao_homens(int *pontos, float *risco){//Coloca de Maneira formatada o risco cardiovascular para homens
    if(*pontos <= -3){
        printf("Risco: <1 %%");
    } else if(*pontos == -2)
    {
        *risco = 1.1;
    } else if (*pontos == -1)
        *risco = 1.4;
    else if(*pontos == 0)
        *risco = 1.6;
    else if(*pontos == 1)
        *risco = 1.9;
    else if(*pontos == 2)
        *risco = 2.3;
    else if(*pontos == 3)
        *risco = 2.8;
    else if(*pontos == 4)
        *risco = 3.3;
    else if(*pontos == 5)
        *risco = 3.9;
    else if(*pontos == 6)
        *risco = 4.7;
    else if(*pontos == 7)
        *risco = 5.6;
    else if(*pontos == 8)
        *risco = 6.7;
    else if(*pontos == 9)
        *risco = 7.9;
    else if(*pontos == 10)
        *risco = 9.4;
    else if(*pontos == 11)
        *risco = 11.2;
    else if(*pontos == 12)
        *risco = 13.2;
    else if(*pontos == 13)
        *risco = 15.6;
    else if(*pontos == 14)
        *risco = 18.4;
    else if(*pontos == 15)
        *risco = 21.6;
    else if(*pontos == 16)
        *risco = 25.3;
    else if(*pontos == 17)
        *risco = 29.4;
    else if(*pontos >= 18)
        *risco = 30;

} //void pontuacao_homens(int *pontos, float *risco) (Linha 160)
void pontuacao_mulheres(int *pontos, float *risco){//Coloca de Maneira formatada o risco cardiovascular para mulheres
    if(*pontos <= -2){
        printf("Risco: <1 %%");
    } else if(*pontos == -1)
    {
        *risco = 1.0;
    } else if (*pontos == 0)
        *risco = 1.2;
    else if(*pontos == 1)
        *risco = 1.5;
    else if(*pontos == 2)
        *risco = 1.7;
    else if(*pontos == 3)
        *risco = 2.0;
    else if(*pontos == 4)
        *risco = 2.4;
    else if(*pontos == 5)
        *risco = 2.5;
    else if(*pontos == 6)
        *risco = 3.3;
    else if(*pontos == 7)
        *risco = 3.9;
    else if(*pontos == 9)
        *risco = 5.3;
    else if(*pontos == 10)
        *risco = 6.3;
    else if(*pontos == 11)
        *risco = 7.3;
    else if(*pontos == 12)
        *risco = 8.6;
    else if(*pontos == 13)
        *risco = 10.0;
    else if(*pontos == 14)
        *risco = 11.7;
    else if(*pontos == 15)
        *risco = 13.7;
    else if(*pontos == 16)
        *risco = 15.9;
    else if(*pontos == 17)
        *risco = 18.5;
    else if(*pontos == 18)
        *risco = 21.6;
    else if(*pontos == 19)
        *risco = 24.8;
    else if(*pontos == 20)
        *risco = 28.5;
    else if(*pontos >= 21)
        *risco = 30;
} // void pontuacao_mulheres(int *pontos, float *risco) (Linha 208)
void calculo_risco_cardiovascular(){//Faz a conta de risco cardiovascular geral,Masculino e Feminino
	/*Bloco de Declaracoes*/
    int idade, HDL, colesterol, PAS_nao_tratada, PAS_tratada;
    int pontos = 0, sexo;
    int fuma, diabetes;
    float risco;
	/*Fim do Bloco de Declaracoes*/
    printf("\n\n---Calculadora de risco cardiovascular---\n");

    printf("\nSexo: ");
    printf("\n1 - Feminino\n2 - Masculino\n");
    printf("--> ");
    scanf("%d", &sexo);

    switch(sexo)
    {
        //---Feminino---//

        case 1: 
        printf("\nIdade: ");
        scanf("%d", &idade);
		
		//---Idade---//
		
        if(idade >= 30 && idade < 34)
    {
        pontos = 0;
    } else if (idade >= 35 && idade <= 39)
    {
        pontos = 2;
    } else if(idade >= 40 && idade <= 44)
    {
        pontos = 4;
    } else if(idade >= 45 && idade <= 49)
    {
        pontos = 5;
    } else if(idade >= 50 && idade <= 54)
    {
        pontos = 7;
    } else if(idade >= 55 && idade <= 59)
    {
        pontos = 8;
    } else if(idade >= 60 && idade <= 64)
    {
        pontos = 9;
    } else if(idade >= 65 && idade <= 69)
    {
        pontos = 10;
    } else if (idade >= 70 && idade <= 74)
    {
        pontos = 11;
    } else if (idade >= 75)
    {
        pontos = 12;
    }


	//---Nivel de HDL-C---//
    printf("\nNivel de HDL - C\n");
    printf("1 - >=60 mg/DL\n2 - 50 a 59 mg/dL\n3 - 45 a 49 mg/dL\n4 - 35 a 44 mg/dL\n5 - <35mg/dL\n");
    printf("--> ");
    scanf("%d", &HDL);

    switch (HDL){
        case 1: pontos += -2;
        break;

        case 2: pontos += -1;
        break;

        case 3: pontos += 0;
        break;

        case 4: pontos += 1;
        break;

        case 5: pontos += 2;
        break;
    }
	//---Colesterol total---//
    printf("\nColesterol total: ");
    printf("\n1 - <160mg/dL\n2 - 160 a 199 mg/dL\n3 - 200 a 239 mg/dL\n4 - 240 a 279 mg/dL\n5 - >=280 mg/dL\n");
    printf("-->");
    scanf("%d", &colesterol);

    switch(colesterol)
    {
        case 1: pontos += 0;
        break;

        case 2: pontos += 1;
        break;

        case 3: pontos += 3;
        break;

        case 4: pontos += 4;
        break;

        case 5: pontos += 5;
        break;
    }
	//---Pressao Arterial Sistolica - nao tratada---//
    printf("\nPressão Arterial Sistólica - não tratada: ");
    printf("\n1 - <120 mmHg\n2 - 120 a 129 mmHg\n3 - 130 a 139 mmHg\n4 - 140 a 149 mmHgL\n5 - 150 a 159 mmHg\n6 - >= 160 mmHg\n");
    printf("-->");
    scanf("%d", &PAS_nao_tratada);

    switch(PAS_nao_tratada)
    {
        case 1: pontos += -3;
        break;

        case 2: pontos += 0;
        break;

        case 3: pontos += 1;
        break;

        case 4: pontos += 2;
        break;

        case 5: pontos += 4;
        break;

        case 6: pontos += 5;
        break;
    }
	//---Pressao Arterial Sistolica - tratada---//
    printf("\nPressão Arterial Sistólica - tratada: ");
    printf("\n1 - <120 mmHg\n2 - 120 a 129 mmHg\n3 - 130 a 139 mmHg\n4 - 140 a 149 mmHgL\n5 - 150 a 159 mmHg\n6 - >= 160 mmHg\n");
    printf("\n-->");
    scanf("%d", &PAS_tratada);

    switch(PAS_tratada)
    {
        case 1: pontos += -1;
        break;

        case 2: pontos += 2;
        break;

        case 3: pontos += 3;
        break;

        case 4: pontos += 5;
        break;

        case 5: pontos += 6;
        break;

        case 6: pontos += 7;
        break;
    }
	//---Fuma---//
    printf("\nFuma: ");
    printf("\n1 - Sim\n2 - Não\n");
    printf("-->");
    scanf("%d", &fuma);
	
    switch(fuma)
    {
        case 1: pontos += 3;
        break;

        case 2: pontos += 0;
        break;
    }
	//---Possui diabetes---//
    printf("\nPossui diabetes: ");
    printf("\n1 - Sim\n2 - Não\n");
    printf("-->");
    scanf("%d", &diabetes);

    switch(diabetes)
    {
        case 1: pontos += 4;
        break;

        case 2: pontos += 0;
        break;
    }

       pontuacao_mulheres(&pontos, &risco);
        
        if(risco < 5){
			printf("\nRisco baixo\n");
			printf("\nPontos: %d\nRisco: %.1f%%\n", pontos, risco);
		} 
		else if(risco < 10){
			printf("\nRisco Intermedi�rio");
			printf("\nPontos: %d\nRisco: %.1f%%\n", pontos, risco);
		}
		else if (risco > 10){
			printf("\nRisco Alto");
			printf("\nPontos: %d\nRisco: %.1f%%\n", pontos, risco);
		}
		else if(risco > 50){
			printf("\nRisco muito alto");
			printf("\nRisco: >50%%");

        break;



       //---Masculino---//
       
        
        case 2: 
            printf("\nIdade: ");
            scanf("%d", &idade);


        //---Idade---//
        if(idade >= 30 && idade < 34)
        {
        pontos = 0;
        } else if (idade >= 35 && idade <= 39)
        {
        pontos = 2;
        } else if(idade >= 40 && idade <= 44)
        {
        pontos = 5;
        } else if(idade >= 45 && idade <= 49)
        {
        pontos = 6;
        } else if(idade >= 50 && idade <= 54)
        {
        pontos = 8;
        } else if(idade >= 55 && idade <= 59)
        {
        pontos = 10;
        } else if(idade >= 60 && idade <= 64)
        {
        pontos = 11;
        } else if(idade >= 65 && idade <= 69)
        {
        pontos = 12;
        } else if (idade >= 70 && idade <= 74)
        {
        pontos = 14;
        } else if (idade >= 75)
        {
            pontos = 15;
        }



        //---Nivel de HDL-C---//

        printf("\nNivel de HDL - C\n");
        printf("1 - >=60 mg/DL\n2 - 50 a 59 mg/dL\n3 - 45 a 49 mg/dL\n4 - 35 a 44 mg/dL\n5 - <35mg/dL\n");
        printf("--> ");
        scanf("%d", &HDL);

        switch (HDL){
            case 1: pontos += -2;
            break;

            case 2: pontos += -1;
            break;

            case 3: pontos += 0;
            break;

            case 4: pontos += 1;
            break;

            case 5: pontos += 2;
            break;
        }

        //---Colesterol total---//
        printf("\nColesterol total: ");
        printf("\n1 - <160mg/dL\n2 - 160 a 199 mg/dL\n3 - 200 a 239 mg/dL\n4 - 240 a 279 mg/dL\n5 - >=280 mg/dL\n");
        printf("-->");
        scanf("%d", &colesterol);

        switch(colesterol)
        {
            case 1: pontos += 0;
            break;

            case 2: pontos += 1;
            break;

            case 3: pontos += 2;
            break;

            case 4: pontos += 3;
            break;

            case 5: pontos += 4;
            break;
        }

        //---Pressao Arterial Sistolica - nao tratada---//
        printf("\nPressão Arterial Sistólica - não tratada: ");
        printf("\n1 - <120 mmHg\n2 - 120 a 129 mmHg\n3 - 130 a 139 mmHg\n4 - 140 a 159 mmHgL\n5 - >= 160 mmHg\n");
        printf("-->");
        scanf("%d", &PAS_nao_tratada);

        switch(PAS_nao_tratada)
        {
            case 1: pontos += -2;
            break;

            case 2: pontos += 0;
            break;

            case 3: pontos += 1;
            break;

            case 4: pontos += 2;
            break;

            case 5: pontos += 3;
            break;

        }

        //---Pressao Arterial Sistolica - tratada---//
        printf("\nPressão Arterial Sistólica - tratada: ");
        printf("\n1 - <120 mmHg\n2 - 120 a 129 mmHg\n3 - 130 a 139 mmHg\n4 - 140 a 159 mmHgL\n5 - >= 160 mmHg\n");
        printf("-->");
        scanf("%d", &PAS_tratada);

        switch(PAS_tratada)
        {
            case 1: pontos += 0;
            break;

            case 2: pontos += 2;
            break;

            case 3: pontos += 3;
            break;

            case 4: pontos += 4;
            break;

            case 5: pontos += 5;
            break;

    
        }

        //---Fuma---//
        printf("\nFuma: ");
        printf("\n1 - Sim\n2 - Não\n");
        printf("-->");
        scanf("%d", &fuma);

        switch(fuma)
        {
            case 1: pontos += 4;
            break;

            case 2: pontos += 0;
            break;
        }

        //---Possui diabetes---//
        printf("\nPossui diabetes: ");
        printf("\n1 - Sim\n2 - Não\n");
        printf("-->");
        scanf("%d", &diabetes);

        switch(diabetes)
        {
            case 1: pontos += 3;
            break;

            case 2: pontos += 0;
            break;
        }
        
		pontuacao_homens(&pontos, &risco);
       
		
		if(risco < 5){
			printf("\nRisco baixo\n");
			printf("\nPontos: %d\nRisco: %.1f%%\n", pontos, risco);
		} 
		else if(risco < 20){
			printf("\nRisco Intermedi�rio");
			printf("\nPontos: %d\nRisco: %.1f%%\n", pontos, risco);
		}
		else if (risco > 20){
			printf("\nRisco Alto");
			printf("\nPontos: %d\nRisco: %.1f%%\n", pontos, risco);
		}
		else if(risco > 50){
			printf("\nRisco muito alto");
			printf("\nRisco: >50%%");
		}
        
    }

    }
    
} // void calculo_risco_cardiovascular(){ Linha(257)
void buscar_hospitais(){//Faz a Busca dos Hospitais por estado, mostrando as cidades registradas no mesmo
	char estado[3];
    printf("\nQual sigla do estado que deseja ver a quantidade de hospitais por cidade? ");
    fflush(stdin);
    fgets(estado, 3, stdin);
    if(stricmp(estado, "PR") == 0){
        printf("\nCuritiba: 10");
        printf("\nCornelio Procopio: 2");
        printf("\nLondrina: 4");
        printf("\nPonta Grossa: 2");
        printf("\nDois Vizinhos: 2");
    }else if(stricmp(estado, "RJ") == 0){
        printf("\nRio de Janeiro: 10");
        printf("\nAraruama: 1");
        printf("\nNiteroi: 2");
    }else if(stricmp(estado, "SP") == 0){
        printf("\nSão Paulo: 13");
        printf("\nJaú: 1");
        printf("\nOurinhos: 2");
    }
    else{
        printf("ESTADO INEXISTENTE / NÃO EXISTE NO NOSSO BANCO DE DADOS");
    }
}// void buscar_hospitais(){ (Linha 659)
void buscar_remedio(medico *medico){ //Faz a Busca de Remedios permitidos a receita por medicos
    int op;
    if (strcmp(medico->especialidade, "Pediatra") == 0){
        printf("\n\nQual endereço de hospital que você deseja visualizar? ");
        scanf("%d", &op);
        if(op == 1){
            printf("\nCaixas de ACETATO DE TOCOFEROL: 7");
            printf("\nCaixas de ACETILCISTEÍNA: 2");
            printf("\nCaixas de ACICLOVIR: 1");
            printf("\nCaixas de ÁCIDO FOLICO: 1");
            printf("\nCaixas de TRAMADOL: 2");
        }else if(op == 2){
            printf("\nCaixas de ACETATO DE TOCOFEROL: 1");
            printf("\nCaixas de ACETILCISTEÍNA: 1");
            printf("\nCaixas de ACICLOVIR: 0");
            printf("\nCaixas de ÁCIDO FOLICO: 7");
            printf("\nCaixas de TRAMADOL: 7");
        }else if(op == 3){
            printf("\nCaixas de ACETATO DE TOCOFEROL: 13");
            printf("\nCaixas de ACETILCISTEÍNA: 13");
            printf("\nCaixas de ACICLOVIR: 13");
            printf("\nCaixas de ÁCIDO FOLICO: 13");
            printf("\nCaixas de TRAMADOL: 13");
        }
    }else if(strcmp(medico->especialidade, "Ortopedista") == 0){
        printf("Qual endereço de hospital que você deseja visualizar? ");
        scanf("%d", &op);
        if(op == 1){
            printf("\nSynvisc One 6 Ml 1 Seringa: 7");
            printf("\nSynvisc Classic 2 Ml 1 Seringa: 2");
            printf("\nOsteonil Plus Seringa Preenchida 40Mg: 1");
            printf("\nViscoseal 50Mg: 1");
            printf("\nMiacalcic 100UI: 2");
        }else if(op == 2){
            printf("\nSynvisc One 6 Ml 1 Seringa: 2");
            printf("\nSynvisc Classic 2 Ml 1 Seringa: 2");
            printf("\nOsteonil Plus Seringa Preenchida 40Mg: 2");
            printf("\nViscoseal 50Mg: 1");
            printf("\nMiacalcic 100UI: 2");
        }else if(op == 3){
            printf("\nSynvisc One 6 Ml 1 Seringa: 13");
            printf("\nSynvisc Classic 2 Ml 1 Seringa: 13");
            printf("\nOsteonil Plus Seringa Preenchida 40Mg: 13");
            printf("\nViscoseal 50Mg: 13");
            printf("\nMiacalcic 100UI: 13");
        }
    }       
} // void buscar_remedio(medico *medico){ (Linha 683)
