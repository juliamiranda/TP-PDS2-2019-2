#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <istream>
//#include "programa.cpp"
#include <bits/stdc++.h>


/*struct unidade{
    string tipoCusto;
    string tipoFatura;
    string codigo;
    string ps;
    int matricula;
    string nome;
    bool periodoDe;
    bool periodoAte;
    string descricao;
    string info;
    float unit;
    float qt;
    float txAdm;
    float total;
    string nomeUnidade;
    bool dataDoLancamentoDeCusto;
};*/

using namespace std;

int main(){

    ifstream arquivo;
    arquivo.open ("Detalhamento_356911.csv");
    if (! arquivo){
        cout << "O arquivo nao foi aberto";
    }//fecha abertura de arquivo
    int n = 0;
    int *linhasNaoNulas[] = {0};
    string arquivosSalvos[] = "";
    int linhaRepeticao = 0;
    int numeroLinhas;

    do{
        string subUnidade;
        string temporario;
        numeroLinhas = 0;
        string nomeArquivo = "";
        int *linhaControle[] = {0};
        //int linha = *linhasNaoNulas[n];
        int linha = 0;

        while (getline(arquivo, subUnidade)){
            linha += 1;
            numeroLinhas =+ 1;
            cout << "O tamanho de subUnidade e: " << subUnidade.size() << endl;
            temporario = "";
            int tab = 0;
            for (int i = 0; i < subUnidade.size(); i++){
                //int tab = 0;
                if (subUnidade[i] == ';'){
                    cout << "Estamos na linha " << linha << endl;
                    tab += 1;
                } //fecha if ;
                if (tab == 14){
                    for (int j = (i+1); j < (i+12); j++){
                            temporario += subUnidade[j];
                            if (j == (i+11)){
                                cout << "O valor atual da unidade e: " << temporario << endl;
                            }
                        } //fecha for j
                tab = -20;
                } //fecha tab == 14
            } //fecha for i
            if (linha > 1) {
                if (linha > *linhaControle[linha-2]){
                    if (nomeArquivo == ""){

                        //testo se ja existe. Se nao existe, segue abaixo
                        int existe = 0;
                        for (int q = 0; q < n; q++){
                            if (arquivosSalvos[q] == temporario)
                            existe += 1;
                        }
                        if (existe == 0){
                            string nomeArquivo = temporario + ".csv";
                            cout << "O nome do arquivo e: " << nomeArquivo << endl;
                            ofstream novoArquivo;
                            novoArquivo.open(nomeArquivo.c_str());
                            linhaControle[1] = 0;
                            //Acrescentar a linha atual ao arquivo
                        }
                    }
                    else{
                        if (nomeArquivo == (temporario + ".csv")){
                            //Verifico se e igual a algum temporario ja salvo. Se sim, nao faz nada. Se nao continua.
                            //Adiciona a linha atual ao arquivo
                            linhaControle[linha-1] = 0;
                        }
                        if (nomeArquivo != (temporario + ".csv")){
                            //Nada e feito.
                            //int *linhaControle[];
                            *linhaControle[linha-1] = linha;
                        }
                    }//fecha else nome do arquivo
                }//fecha if maior que linha de controle
            }//fecha if maior que 1
        }//fecha while
        int m = 1;
        for (int k = 0; k < linha; k++){
            if (linhaControle[k] != 0){
                linhasNaoNulas[m] = linhaControle[k];
                m++;
            }
        }
        linhaRepeticao = *linhasNaoNulas[n];
        arquivosSalvos[n] = nomeArquivo;
        n++;
    }while (linhaRepeticao <= numeroLinhas);
    //Repete o while a partir da linha salva enquanto não chegou no fim do arquivo.

    return 0;
}//fecha main
