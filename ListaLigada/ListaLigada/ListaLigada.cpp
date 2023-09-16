#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento() {

    int elemento;
    cout << "Digite o elemento que deseja inserir: ";
    cin >> elemento;
    
    if (posicaoElemento(elemento) == NULL){
        
    	NO* novo = (NO*)malloc(sizeof(NO));
    	if (novo == NULL)
    	{
    		return;
    	}
    
        novo->valor = elemento;
    	novo->prox = NULL;
    
    	if (primeiro == NULL)
    	{
    		primeiro = novo;
    	}
    	else
    	{
    		NO* aux = primeiro;
    		while (aux->prox != NULL) {
    			aux = aux->prox;
    		}
    		aux->prox = novo;
    	}
    }
    else
    {
        cout << "O elemento já está na lista. \n";
        cout << endl;
    }
}

void excluirElemento()
{
	int delNum;
	bool zero = true;
	bool del = false;
	
	cout << "Digite o elemento a ser excluído: ";
	cin >> delNum;
	
	NO* indice = primeiro;
	NO* anterior;
	
	if (posicaoElemento(delNum) == NULL){
	    cout << "Elemento não encontrado.\n";
	    cout << endl;
	}
	    
	while (indice != NULL && posicaoElemento(delNum) != NULL){
	   
	    if (zero == true){
	        if (indice->valor == delNum){
	            primeiro = indice->prox;
	            free (indice);
	            cout << "Elemento excluído com sucesso. \n";
	            cout << endl;
	            del = true;
	        }
	        else{
	            anterior = indice;
	        }
	        zero = false;
	    }
	    else{
	        if (indice->valor == delNum){
	            anterior->prox = indice->prox;
	            free (indice);
	            del = true;
	        }
	        else
	        {
	            anterior=indice;
	        }
	    }
	    if (del){
	        del = false;
	        break;
	    }
	    indice = indice->prox;
	}

}

void buscarElemento()
{
	int buscarNum;
	if (primeiro != NULL){
	    cout << "Digite o elemento que está procurando: ";
	    cin >> buscarNum;
	    
	    if (posicaoElemento(buscarNum) != NULL){
	        cout << "Elemento Encontrado\n";
	        cout << "A posição que ele se encontra atualmente é:";
	        cout << posicaoElemento;
	        cout << endl;
	    }
	    else{
	        cout << "Elemento não encontrado. \n";
	        cout << endl;
	    }
	}
	else{
	    cout << "A lista está vazia. \n";
	    cout << endl;
	}
	
}


NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
