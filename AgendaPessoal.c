//Marcus Vinicius Silva Lobo Felipe - 172050070

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Pessoa{
    char* nome;
    char* email;
    int idade;
    char telefone[100];
    char* endereco;
    char* cidade;
    char estado[2];
    char* tarefa;
    char* reuniao;
    char* aniversario;
    int graudeesforco;
    int prioridade;
    int horainiciotarefa;
    int horafimtarefa;
    int horainicioreuniao;
    int horafimreuniao;
    int horainicioaniversario;
    int horafimaniversario;
}pessoa[MAX];

//menu de opções do inicio do programa
void exibirMenu(){
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\t01 - Inserir contato\n"
           "\t02 - Entrar na agenda de um contato\n"
           "\t03 - Listar contatos\n"
           "\t99 - Sair\n\n");
}
//aloca espaço de memória dos ponteiros para realizar a copia dos dados
char* alocarMemoria(int tamanho){
    char* info = NULL;
    info = (char*) malloc(sizeof(tamanho) * sizeof(char));

    if(info == NULL){
        printf("ERRO: impossível alocar a quantidade de memória requisitada!");
        exit(1);
    }
    return info;
}

//função para cadastrar usuário na agenda
void cadastrarUsuario(int registro){
    char dados[MAX];
    printf("\n\t\tNome: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].nome = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].nome, dados);
    setbuf(stdin, NULL);

    printf("\n\t\tEmail: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].email = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].email, dados);
    setbuf(stdin, NULL);

    printf("\t\tIdade: ");
    scanf("%d", &pessoa[registro].idade);
    setbuf(stdin, NULL);

    printf("\t\tTelefone: ");
    scanf("%[^\n]s", pessoa[registro].telefone);
    setbuf(stdin, NULL);

    printf("\t\tEndereço: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].endereco = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].endereco, dados);
    setbuf(stdin, NULL);

    printf("\t\tCidade: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].cidade = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].cidade, dados);
    setbuf(stdin, NULL);

    printf("\t\tEstado: ");
    scanf("%[^\n]s", pessoa[registro].estado);

}

//Função para cadastrar tarefa de um determinado usuario
void cadastrartarefa(int registro){
    char dados[MAX];
    printf("\n\tNome da Tarefa: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].tarefa = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].tarefa, dados);

    printf("\tEndereço: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].endereco = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].endereco, dados);

    printf("\tHorário do inicio da tarefa: ");
    scanf("%d", &pessoa[registro].horainiciotarefa);

    printf("\tHorário do fim da tarefa: ");
    scanf("%d", &pessoa[registro].horafimtarefa);

    printf("\tGrau de esforco da tarefa: ");
    scanf("%d", &pessoa[registro].graudeesforco);

    printf("\tPrioridade da tarefa: ");
    scanf("%d", &pessoa[registro].prioridade);

    printf("\n\tTarefa: %s" , pessoa[registro].tarefa);
    printf("\n");
    printf("\tLocal: %s" , pessoa[registro].endereco);
    printf("\n");
    
    if(pessoa[registro].graudeesforco < 1 && pessoa[registro].graudeesforco > 5){
        printf("\tO grau de esforço da tarefa deve ser um numero de 0 a 5!!\n");
    }else{
        printf("\tGrau de esforço: %d", pessoa[registro].graudeesforco);
        printf("\n");
    }
    if(pessoa[registro].prioridade < 1 && pessoa[registro].prioridade > 5){
        printf("\tA prioridade da tarefa deve ser um numero de 0 a 5!!\n");
    }else{
        printf("\tPrioridade: %d", pessoa[registro].prioridade);
        printf("\n");
    }


    if(pessoa[registro].horainiciotarefa >= 0 && pessoa[registro].horainiciotarefa <= 23){  //verifica se os horarios estão entre 0 e 23 horas.
        if(pessoa[registro].horainiciotarefa == pessoa[registro].horainicioreuniao){        //verifica se os horarios de reuniões, tarefas e aniversários coincidem.
        printf("\tHorario da tarefa igual o de reunião, favor colocar horários diferentes!\n");
        exit(1);
        }else if(pessoa[registro].horafimtarefa == pessoa[registro].horafimreuniao){
        printf("\tHorario da tarefa igual o de reunião, favor colocar horários diferentes!\n");
        exit(1);
        }else if(pessoa[registro].horainiciotarefa == pessoa[registro].horainicioaniversario){
        printf("\tHorario da tarefa igual o de aniversario, favor colocar horários diferentes!\n");
        exit(1);
        }
        printf("\tInicio: %d horas" , pessoa[registro].horainiciotarefa);
        printf("\n");
    }else{
        printf("\tHorário de inicio da tarefa não permitido!!\n");

    }if(pessoa[registro].horafimtarefa >= 0 && pessoa[registro].horafimtarefa <= 23){
        printf("\tFim: %d horas" , pessoa[registro].horafimtarefa);
        printf("\n");
    }else{
        printf("\tHorário final da tarefa não permitido!!\n");
        printf("\tOs horarios são somente das 0 horas as 23 horas!!");
        printf("\n");
        exit(1);
    }
}

//Função para fazer o cadastro de uma reunião do usuário pesquisado!!
void cadastrarreuniao(int registro){
    char dados[MAX];
    printf("\n\tAssunto da reuniao: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].reuniao = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].reuniao, dados);

    printf("\tEndereço: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].endereco = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].endereco, dados);

    printf("\tHorário do inicio da reuniao: ");
    scanf("%d", &pessoa[registro].horainicioreuniao);
    setbuf(stdin, NULL);
    
    printf("\tHorário do fim da reuniao: ");
    scanf("%d", &pessoa[registro].horafimreuniao);
    setbuf(stdin, NULL);

    printf("\n");
    printf("\tAssunto: %s" , pessoa[registro].reuniao);
    printf("\n");
    printf("\tLocal: %s" , pessoa[registro].endereco);
    printf("\n\n");
    if(pessoa[registro].horainicioreuniao >= 0 && pessoa[registro].horainicioreuniao <= 23){ //verifica se os horarios estão entre 0 e 23 horas.
        if(pessoa[registro].horainiciotarefa == pessoa[registro].horainicioreuniao){         //verifica se os horarios de reuniões, tarefas e aniversários coincidem.
        printf("\tHorario da tarefa igual o de reunião, favor colocar horários diferentes!\n");
        exit(1);
        }else if(pessoa[registro].horafimtarefa == pessoa[registro].horafimreuniao){
        printf("\tHorario da tarefa igual o de reunião, favor colocar horários diferentes!\n");
        exit(1);
        }else if(pessoa[registro].horainicioreuniao == pessoa[registro].horainicioaniversario){
        printf("\tHorario da reuniao igual o de aniversario, favor colocar horários diferentes!\n");
        exit(1);
        }else if(pessoa[registro].horafimreuniao == pessoa[registro].horafimaniversario){
        printf("\tHorario da reuniao igual o de aniversario, favor colocar horários diferentes!\n");
        exit(1);
        }
        printf("\tInicio: %d horas" , pessoa[registro].horainicioreuniao);
        printf("\n");
    }else{
        printf("\tHorário de inicio da reunião não permitido!!\n");
    }if(pessoa[registro].horafimreuniao >= 0 && pessoa[registro].horafimreuniao <= 23){ //verifica se os horarios estão entre 0 e 23 horas.
        printf("\tFim: %d horas" , pessoa[registro].horafimreuniao);
        printf("\n");
    }else{
        printf("\tHorário final da reunião não permitido!!\n");
        printf("\tOs horarios são somente das 0 horas as 23 horas!!");
        printf("\n");
        exit(1);
    }
}

//cadastra o aniversário de um determinado usuário
void cadastraraniversario(int registro){
    char dados[MAX];
    printf("\n\tAssunto do Aniversário: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].aniversario = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].aniversario, dados);

    printf("\tEndereço: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].endereco = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].endereco, dados);

    printf("\tHorário do inicio da aniversario: ");
    scanf("%d", &pessoa[registro].horainicioaniversario);
    setbuf(stdin, NULL);
    
    printf("\tHorário do fim da aniversario: ");
    scanf("%d", &pessoa[registro].horafimaniversario);
    setbuf(stdin, NULL);

    printf("\n");
    printf("\tAssunto do Aniversario: %s" , pessoa[registro].aniversario);
    printf("\n");
    printf("\tLocal: %s" , pessoa[registro].endereco);
    printf("\n\n");
    if(pessoa[registro].horainicioaniversario >= 0 && pessoa[registro].horainicioaniversario <= 23){    //verifica se os horarios estão entre 0 e 23 horas.
        if(pessoa[registro].horainiciotarefa == pessoa[registro].horainicioaniversario){                //verifica se os horarios de reuniões, tarefas e aniversários coincidem.
        printf("\tHorario da tarefa igual o de aniversario, favor colocar horários diferentes!\n");
        exit(1);
        }else if(pessoa[registro].horafimtarefa == pessoa[registro].horafimaniversario){
        printf("\tHorario da tarefa igual o de aniversario, favor colocar horários diferentes!\n");     
        exit(1);
        }else if(pessoa[registro].horainicioreuniao == pessoa[registro].horainicioaniversario){
        printf("\tHorario da reuniao igual o de aniversario, favor colocar horários diferentes!\n");
        exit(1);
        }else if(pessoa[registro].horafimreuniao == pessoa[registro].horafimaniversario){
        printf("\tHorario da reuniao igual o de aniversario, favor colocar horários diferentes!\n");
        exit(1);
        }
        printf("\tInicio: %d horas" , pessoa[registro].horainicioaniversario);
        printf("\n");
    }else{
        printf("\tHorário de inicio do aniversário não permitido!!\n");
    }if(pessoa[registro].horafimaniversario >= 0 && pessoa[registro].horafimaniversario <= 23){         //verifica se os horarios estão entre 0 e 23 horas.
        printf("\tFim: %d horas" , pessoa[registro].horafimaniversario);
        printf("\n");
    }else{
        printf("\tHorário final do aniversário não permitido!!\n");
        printf("\tOs horarios são somente das 0 horas as 23 horas!!");
        printf("\n");
        exit(1);
    }
}
//lista todos os contatos e suas informações.
void listarUsuarios(int qtdeContatos){
    int i;
    int contagem = 1;
    for(i = 0; i < qtdeContatos; i++){
        printf("\n\tContato nº: %d\n", contagem++);
        printf("\tNome: %s\n", pessoa[i].nome);
        printf("\tEmail: %s\n", pessoa[i].email);
        printf("\tIdade: %d\n", pessoa[i].idade);
        printf("\tTelefone: %s\n", pessoa[i].telefone);
        printf("\tEndereço: %s\n", pessoa[i].endereco);
        printf("\tCidade: %s-%s\n", pessoa[i].cidade, pessoa[i].estado);
        printf("\tTarefa: %s, De: %d as %d, Prioridade: %d, Grau de esforço: %d\n", pessoa[i+1].tarefa, pessoa[i+1].horainiciotarefa, pessoa[i+1].horafimtarefa, pessoa[i+1].prioridade, pessoa[i+1].graudeesforco);
        printf("\tReuniao: %s, De: %d as %d\n", pessoa[i+1].reuniao, pessoa[i+1].horainicioreuniao, pessoa[i+1].horafimreuniao);
        printf("\tAniversario: %s, De: %d as %d\n", pessoa[i+1].aniversario, pessoa[i+1].horainicioaniversario, pessoa[i+1].horafimaniversario);        
    }
    printf("\n\n");
}
//Função usada para exibir informações do usuario
void exibirUsuario(int indice){
    printf("\n\tNome: %s\n", pessoa[indice].nome);
    printf("\n\tEmail: %s\n", pessoa[indice].email);
    printf("\tIdade: %d\n", pessoa[indice].idade);
    printf("\tTelefone: %s\n", pessoa[indice].telefone);
    printf("\tEndereço: %s\n", pessoa[indice].endereco);
    printf("\tCidade: %s-%s\n\n", pessoa[indice].cidade, pessoa[indice].estado);
}

int pesquisarUsuario(int qtdeContatos, char* nomeBuscado){
    int i;

    for(i = 0; i < qtdeContatos; i++){
        if(strcmp(nomeBuscado, pessoa[i].nome) == 0)
            return i;
    }
    return -1;
}
//função para ler a opção digitada no menu inicial.
int leitor(){
    int opcao;

    printf("\n\tOpção escolhida: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    return opcao;
}

int main(){
    char nome[MAX];
    int numeroRegistro = 0;
    int opcaoEscolhida;
    int indice;

    do{
        exibirMenu();
        opcaoEscolhida = leitor();

        switch(opcaoEscolhida){
            case 1:
                cadastrarUsuario(numeroRegistro++); //opção para cadastro de contato.
                break;
            case 2:
                printf("\n\tNome: ");               //opção que irá permitir preencher a agenda de um contato e mostra-la
                scanf("%[^\n]s", nome);
                indice = pesquisarUsuario(numeroRegistro, nome);
                setbuf(stdin, NULL);

                if(indice >= 0 && indice <= 99){
                    exibirUsuario(indice);
                    printf("\n");                    
                    printf("\tAdicionar obrigacoes a agenda do %s\n", nome);
                    printf("\tCadastro de Tarefa:\n");
                    cadastrartarefa(numeroRegistro);
                    printf("\n");                    
                    setbuf(stdin, NULL);
                    printf("\tCadastro de Reuniao:\n");
                    cadastrarreuniao(numeroRegistro);
                    printf("\n");
                    setbuf(stdin, NULL);
                    printf("\tCadastro de Aniversario:\n");
                    cadastraraniversario(numeroRegistro);
                    printf("\n");                    
                    setbuf(stdin, NULL);
                }
                else{
                    printf("\n\tContato não cadastrado!");
                    printf("\n");
                }                    
                break;
            case 3:
                listarUsuarios(numeroRegistro);     //opção que chama a função para listar contatos e suas informações.
                break;
            case 99:
                printf("\n\tSaindo...");            //opção para sair do programa.
                printf("\n");
                break;
            default:
                printf("Opção inválida!");
                exibirMenu();
                opcaoEscolhida = leitor();
        }

    }while(opcaoEscolhida != 99);                   //looping para manter sempre o menu aberto apos terminar de realizar uma das opções sem erro.
}