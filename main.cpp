#include <iostream>
#include <fstream>
#include <string>


std::string buscacodigoean13(std::string codigodebarrasdigitado) {
    int i;
    std::string produtocodigodebarras;
    std::ifstream arquivodeprodutos("pricetab.txt");
    std::string produto;

    if (!arquivodeprodutos.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return "1";
    };

    std::string linha;
    while (std::getline(arquivodeprodutos, linha)) {
        if (linha[0] == '0') {
            continue;
        } else {
            produtocodigodebarras.clear();
            for (i = 0; linha[i] != '|'; i++) {
                produtocodigodebarras.push_back(linha[i]);
            };

            if (produtocodigodebarras == codigodebarrasdigitado) {
                produto = linha;
                return produto;
            };
        };
    };

    return "produto nao encontrado !";
};


std::string buscacodigoean8(std::string codigodebarrasdigitado) {
    int i;
    std::string produto;    
    std::string produtocodigodebarras;
    std::ifstream arquivodeprodutos("pricetab.txt");

    if(!arquivodeprodutos.is_open()) {
        std::cerr << "Erro ao abrir o arquivo\n";
        return "1";
    };

    std::string linha;
    while (std::getline(arquivodeprodutos, linha)) {        
        if (linha[0] == '0') {
            bool ezero = true;
            produtocodigodebarras.clear();
            for (i = 0; linha[i] != '|';) {
                if (linha[i] == '0' & ezero) {
                    i++;
                } else {
                    ezero = false;
                    //std::cout << linha[i];                    
                    produtocodigodebarras.push_back(linha[i]);
                    i++;
                };                
            };

            if (produtocodigodebarras == codigodebarrasdigitado) {
                //std::cout << "Produto encontrado: " << produtocodigodebarras << "\n";
                produto = linha;
                return produto;
            };
        } else {
            continue;
        };
    };

    return "produto nao encontrado !";
};


int main() {

    bool isTrue = true;
    bool isFalse = false;
    std::string codigodebarrasdigitado;
    std::string linhaproduto;

    std::string produtocodibarra;
    std::string produtodescricao;
    std::string produtopreco;
    int barraseperacao = 0;

    while (isTrue)
    {
        linhaproduto.clear();
        codigodebarrasdigitado.clear();
        produtocodibarra.clear();
        produtodescricao.clear();
        produtopreco.clear();
        barraseperacao = 0;

        std::cout << "\nDigite o codigo de barras('qq' para sair): ";
        std::cin >> codigodebarrasdigitado;

        if (codigodebarrasdigitado == "qq") {
            return 0;
        };

        if (codigodebarrasdigitado[0] == '0') {
            std::cout << "\nDigite apenas o codigo de barras !";
            continue;
        };

        if (codigodebarrasdigitado.length() == 13) {
            linhaproduto = buscacodigoean13(codigodebarrasdigitado);
        } else {
            if (codigodebarrasdigitado.length() >= 1 || codigodebarrasdigitado.length() <= 8) {
                linhaproduto = buscacodigoean8(codigodebarrasdigitado);                                
            };
        };

        if (linhaproduto != "produto nao encontrado !") {            
            for(int i = 0; i < linhaproduto.length(); i++) {

                if (linhaproduto[i] == '|') {
                    barraseperacao++;
                    continue;
                };

                if (barraseperacao == 0) {
                    produtocodibarra.push_back(linhaproduto[i]);
                } else if (barraseperacao == 1) {
                    produtodescricao.push_back(linhaproduto[i]);
                } else if (barraseperacao == 2) {
                    produtopreco.push_back(linhaproduto[i]);
                };
            };
            std::cout << "Codigo de barras....: " << produtocodibarra << "\n";
            std::cout << "Descricao do produto: " << produtodescricao << "\n";
            std::cout << "Preco do produto....: " << "R$ " << produtopreco << "\n";
        } else {
            std::cout << "Produto nao encontrado! \n";
        };
        
    };
    return 0;    
};