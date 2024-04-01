#include <stdio.h>
#include <time.h>
#include <stdlib.h>

    void calcLiteraria() {
        printf("\n");
        printf("\t ┌|||||||||||||||||||||||||||||||||| •✧✧• ||||||||||||||||||||||||||||||||||┐\n");
        printf("\t|									     |\n");
        printf("\t|		 C A L C U L A D O R A  L I T E R Á R I A                    |\n");
        printf("\t|									     |\n");
        printf("\t └|||||||||||||||||||||||||||||||||| •✧✧• ||||||||||||||||||||||||||||||||||┘\n\n\n\n");
    }
    
int main()
{
    int paginasDia=0, paginasLer=0, diasT=0, dias=0, semanas=0, meses=0, anos=0, controleTeste=0;
    char teste='S';
    float tempoLivre=0, tempoTotal=0, minutos=0, tempoGasto=0;
    time_t inicio, fim;
    

    calcLiteraria(); // chama a função

    printf("\t\tBem-vinde ao Calculadora Literária!\n\n");
    printf("\tVamos solicitar alguns dados para calcular sua velocidade de leitura\n"); 
    printf("\te o tempo para ler um livro de sua preferência.\n");
    printf("\n\tEntão, resgate aquele livro pegando poeira na estante e vamos começar!\n");
    
    while(teste=='S' || teste=='s') { //aceita maiúscula ou minúscula
        
        do {
            printf("\n\tInforme o número de páginas do livro que você quer ler: ");
            scanf("%d", &paginasLer);
            if(paginasLer<1) printf("\n\t>>>> Número de páginas inválido! Tente novamente. \n");
        } while(paginasLer<1);
        
        do {
            printf("\n\tQuanto tempo por dia você vai dedicar para a leitura?");
            printf("\n\tInforme o valor em minutos: ");
            scanf("%f", &tempoLivre); //salva a frequência de leitura para o cálculo final.
            if(tempoLivre<1) printf("\n\t>>>> Informe um tempo válido para leitura.\n");
        } while(tempoLivre<1);
        
        printf("\n\tPeque o livro que você vai ler e siga as instruções abaixo: \n\n");
        printf("\n\t\t1- Procure uma página cheia do livro que você quer ler. ");
        printf("\n\t\t2- Encontre um local silencioso e confortável para fazer este teste. \n");
        printf("\n\n\tQuando tudo estiver pronto, digite 1 e inicie a leitura. ");
        printf("\n \t* Ou digite 0 para encerrar o teste. ");
        scanf("%d", &controleTeste); //variável de controle para dar início ao teste.
        system("clear");
        
        calcLiteraria();
        
        if(controleTeste==1) {
            printf("\n\t\t***Teste iniciado***\n");
            time(&inicio); //inicia a contagem do tempo usando o horário do sistema.
            printf("\n\t\t*** Pressione ENTER para terminar a contagem do tempo *** ");
            getchar(); getchar();
            time(&fim); 
        } else {
            teste='n';
            }
        //difftime faz a diferença do horário de início e fim, resposta em segundos.   
        tempoGasto = difftime(fim, inicio);

        system("clear");   
        calcLiteraria();
        
        printf("\n\n\tVocê levou %.f segundos parar ler uma página.\n", tempoGasto);
        
        // Converte o tempo medido em segundos para minutos.
        minutos = tempoGasto/60;
        //tempoGastoInt = tempoGasto;
        
        tempoTotal = (minutos * paginasLer)/ tempoLivre; //tempoLivre é a medida diaria escolhida pelo usuário
        
        paginasDia = tempoLivre/minutos;

        
        // Decompor o tempo de leitura em dias, semanas, meses e anos.
        diasT = tempoTotal;
        anos    =   diasT / 365;
        meses   =  (diasT % 365) / 30;
        semanas = ((diasT % 365) % 30) / 7;
        dias    = ((diasT % 365) % 30) % 7;
        
        //testa o tempo para não imprimir "zero anos, meses ou semanas"
        if(anos<1&&meses<1&&semanas<1&&dias<1) {
            printf("\n\tDados informados insuficientes. \n");
            
        } else {
            printf("\n\n\tA leitura vai levar em torno de %d dia", diasT);
            if(diasT>1) printf("s");
            
            if(diasT!=1) {
                printf("\n\tO que corresponde a ");
                
                if(anos>0) printf(" %d ano", anos);
                if(anos>1) printf("s, ");
                
                if(meses>=1) {
                    printf(" %d m", meses);
                    if(meses>1) printf("eses, ");
                    else printf("ês, ");
                }
                if(semanas>0) printf(" %d semana", semanas);
                if(semanas>1) printf("s ");
                
                if(dias>0) printf(" %d dia", dias);
                if(dias>1) printf("s");
                
                printf(" para ler o livro informado. \n");
            }
            if(dias==1&&anos<1&&meses<1&&semanas<1) printf("\t\nVocê deve ler %d página por dia. \n", dias);
            else printf("\n\tVocê deve ler em média %d páginas por dia. \n", paginasDia);
        }
        printf("\n\tDeseja fazer um novo teste? \n");
        printf("\tDigite S para sim, N para não: ");
        scanf(" %c", &teste); //O espaço antes do % faz com que o scanf() não leia um caractere em branco   
        
        if(teste == 'S' || teste=='s') { 
            system("clear"); //limpa a tela para começar um novo teste.
            calcLiteraria();
        } else printf("\n\tObrigada por usar o Calculadora Literária. \n\tBoa leitura!");
    }
    
    printf("\n\n\n\n\tDesenvolvido por: Daniela Mattos\n");

    return 0;
}













