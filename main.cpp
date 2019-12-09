#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <istream>
#include "programa.cpp"
#include <bits/stdc++.h>

using namespace std;

void aberturaArquivo(){
    ifstream arquivo;
    string UNIDADE;
    arquivo.open ("Detalhamento_356911.csv");
    if (! arquivo){
        cout << "O arquivo nao foi aberto";
    }
}

string selecaoAno(){
    string ANO;
    cout << "Digite o ano (no formato XXXX). Exemplo: 2020: " << endl;
    cin >> ANO;
    if (ANO < "2011"){
        cout << "Voce nao digitou um ano valido." << endl;
        cout << "Digite: \n1 para voltar ao menu anterior ou \n2 para voltar ao menu principal." << endl;
        int volta = 0;
        cin >> volta;
        if (volta == 1){
            ANO = "escolhaAno"; //Selecao de diretorio volta para a escolha do ano.
        }
        if (volta == 2){
            ANO = "menuPrincipal"; //Selecao de diretorio volta para o menu principal.
        }
        if ((volta != 1) && (volta != 2)){
            cout << "Voce nao digitou uma opcao valida" << endl;
            ANO = "encerrarPrograma"; //Selecao de diretorio encerra o programa.
        }
    }
    return ANO;
}

string selecaoMes(){
    int mes;
    string MES2;
    cout << "Digite o mes (no fotmato XX). Exemplo para novembro: 11: " << endl;
    cin >> mes;
    switch (mes){
        case 1:
            MES2 = "\\001- JANEIRO";
            break;
        case 2:
            MES2 = "\\002- FEVEREIRO" ;
            break;
        case 3:
            MES2 = "\\003- MARÇO";
            break;
        case 4:
            MES2 = "\\004- ABRIL";
            break;
        case 5:
            MES2 = "\\005- MAIO";
            break;
        case 6:
            MES2 = "\\006- JUNHO";
            break;
        case 7:
            MES2 = "\\007- JULHO";
            break;
        case 8:
            MES2 = "\\008- AGOSTO";
            break;
        case 9:
            MES2 = "\\009- SETEMBRO";
            break;
        case 10:
            MES2 = "\\010- OUTUBRO";
            break;
        case 11:
            MES2 = "\\011- NOVEMBRO";
            break;
        case 12:
            MES2 = "\\012- DEZEMBRO";
            break;
        default:{
            cout << "Voce nao digitou um mes valido." << endl;
            cout << "Digite: \n1 para voltar ao menu anterior ou \n2 para voltar ao menu principal." << endl;
            int volta = 0;
            cin >> volta;
            if (volta == 1){
                MES2 = "escolhaMes"; //Selecao de diretorio volta para a escolha do mes.
            }
            if (volta == 2){
                MES2 = "menuPrincipal"; //Selecao de diretorio volta para o menu principal.
            }
            if ((volta != 1) && (volta != 2)){
                cout << "Voce nao digitou uma opcao valida" << endl;
                MES2 = "encerrarPrograma"; //Selecao de diretorio encerra o programa.
            }
        }
    }
    return MES2;
}

string selecaoContrato(){
    int opcaoContrato = 0;
    string CONTRATO;
    cout << "Escolha o contrato: " << endl;
    cout << "1 - Apoio Operacional \n2 - BH Resolve \n3 - Restaurante \n4 - Voltar ao menu anterior \n5 - Voltar ao menu principal" << endl;
    cin >> opcaoContrato;
    switch (opcaoContrato){
        case 1:
            CONTRATO = "APOIO OPERACIONAL";
            break;
        case 2:
            CONTRATO = "BH RESOLVE - vigente a partir de 25.04.2019";
            break;
        case 3:
            CONTRATO = "SUSAN (NOVO CONTRATO)";
            break;
        case 4:
            CONTRATO = "escolhaMes"; //Selecao de diretorio volta para a escolha do mes.
            break;
        case 5:
            CONTRATO = "menuPrincipal"; //Selecao de diretorio volta para o menu principal.
        break;
        default:
            cout << "Voce digitou uma opcao errada de contrato." << endl;
            cout << "Digite: \n1 para voltar ao menu anterior ou \n2 para voltar ao menu principal." << endl;
            int volta = 0;
            cin >> volta;
            //cin.ignore();
            if (volta == 1){
                CONTRATO = "escolhaContrato"; //Selecao de diretorio volta para a escolha do contrato.
            }
            if (volta == 2){
                CONTRATO = "menuPrincipal"; //Selecao de diretorio volta para o menu principal.
            }
            if ((volta != 1) && (volta != 2)){
                cout << "Voce nao digitou uma opcao valida" << endl;
                CONTRATO = "encerrarPrograma"; //Selecao de diretorio encerra o programa.
            }
    }
    return CONTRATO;
}

string ComposicaoDiretorio(){

    string diretorioGeral;
    string ano;
    string mes2;
    string contrato;
    string DIRETORIODOMES;
    string nomeArquivo = "\\teste.csv";

    diretorioGeral = "\\\\PC991006729900\\smad 152\\MGS\\FATURAMENTO";

    ano:
    string selecaoAno();
    ano = selecaoAno();
    if (ano == "escolhaAno"){
        goto ano;
    }
    if ((ano == "menuPrincipal") || (ano == "encerrarPrograma")){
        DIRETORIODOMES = ano;
        goto fimComposicaoDiretorio;
    }

    mes:
    string selecaoMes();
    mes2 = selecaoMes();
    if (mes2 == "escolhaMes"){
        goto mes;
    }
    if ((mes2 == "menuPrincipal") || (mes2 == "encerrarPrograma")){
        DIRETORIODOMES = mes2;
        goto fimComposicaoDiretorio;
    }

    contrato:
    string selecaoContrato();
    contrato = selecaoContrato();
    if (contrato == "escolhaMes"){
        goto mes;
    }
    if (contrato == "escolhaContrato"){
        goto contrato;
    }
    if ((contrato == "menuPrincipal") || (contrato == "encerrarPrograma")){
        DIRETORIODOMES = contrato;
        goto fimComposicaoDiretorio;
    }

    DIRETORIODOMES = diretorioGeral + "\\" + ano + "\\" + mes2 + "\\" + contrato + nomeArquivo;
    cout << "Diretorio para salvar e: " << DIRETORIODOMES << endl;

    char testeSalvar [100];
    strcpy(testeSalvar, DIRETORIODOMES.c_str());
    fopen(testeSalvar, "w");

    fimComposicaoDiretorio:

    return DIRETORIODOMES;
}

int main(){

    aberturaArquivo();

    string diretorioDoMes;

    menuPrincipal:
    cout << "Estamos no inicio do programa" << endl;
    //ComposicaoDiretorio();
    diretorioDoMes = ComposicaoDiretorio();
    if (diretorioDoMes == "menuPrincipal"){
        goto menuPrincipal;
    }
    if (diretorioDoMes == "encerrarPrograma"){
        goto encerrarPrograma;
    }
    //cout << "\n\nDIRETORIO NO MAIN:\n" << diretorioDoMes;

    /*else{
        while (getline(arquivo,UNIDADE)){
            cout << UNIDADE << endl;
        }
    }*/
    //while (arquivo >> UNIDADE)
        //cout << setiosflags(ios::left)
             //<< setw(11) << UNIDADE;

    encerrarPrograma:
    cout << "Chegamos ao fim do programa";

    return 0;
}
