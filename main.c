#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
	char name[sizeof(char)*40];
	char number[sizeof(char)*15];
	char cellphone[sizeof(char)*15];
	char email[sizeof(char)*40];
	char brith[sizeof(char)*5];
} Contact;

void addContact(Contact **data, int *size, Contact contact1) {
	Contact *temp = realloc(*data, (*size + 1) * sizeof(Contact));

	if (temp == NULL) {
		printf("Erro ao realocar memoria\n");
	} else {
		*data = temp;
		(*data)[*size] = contact1;
		(*size)++;
	}
}

void editContact(Contact *data, int size, char *search) {
	for (int i = 0; i < size; i++) {
		if (strcmp(data[i].name, search) == 0) {
			printf("Editar contato: %s\n", data[i].name);

			printf("Digite o novo nome: ");
			scanf("%s", data[i].name);
			printf("Digite o novo número: ");
			scanf("%s", data[i].number);
			printf("Digite o novo telefone: ");
			scanf("%s", data[i].cellphone);
			printf("Digite o novo aniversário: ");
			scanf("%s", data[i].brith);
			printf("Digite o novo email: ");
			scanf("%s", data[i].email);

			printf("Contato editado com sucesso!\n");
			return;
		}
	}
	printf("Contato não encontrado!\n");
}

void removeContact(Contact **data, int *size, char *search) {
	for (int i = 0; i < *size; i++) {
		if (strcmp((*data)[i].name, search) == 0) {
			for (int j = i; j < *size - 1; j++) {
				(*data)[j] = (*data)[j + 1];
			}
			*size -= 1;
			*data = realloc(*data, (*size) * sizeof(Contact));
			printf("Contato removido com sucesso!\n");
			return;
		}
	}
	printf("Contato não encontrado!\n");
}

int main() {
	setlocale(LC_ALL, "");

	Contact *data = NULL; 
	int size = 0; 
	int option;

	do {
		printf("\nSelecione uma opção:\n");
		printf("1. Listar Contatos\n");
		printf("2. Inserir Contato\n");
		printf("3. Buscar Contato\n");
		printf("4. Editar Contato\n");
		printf("5. Remover Contato\n");
		printf("6. Sair\n");

		scanf("%d", &option);

		if (option == 1) {
			if (size == 0) {
				printf("Nenhum contato adicionado.\n");
			} else {
				for (int i = 0; i < size; i++) {
					printf("Nome: %s\n", data[i].name);
					printf("Número: %s\n", data[i].cellphone);
					printf("Telefone: %s\n", data[i].number);
					printf("Aniversário: %s\n", data[i].brith);
					printf("Email: %s\n\n", data[i].email);
				}
			}
		} else if (option == 2) {
			Contact contact1;
			printf("Digite o nome: ");
			scanf("%s", contact1.name);
			printf("Digite o número: ");
			scanf("%s", contact1.number);
			printf("Digite o telefone: ");
			scanf("%s", contact1.cellphone);
			printf("Digite o aniversário: ");
			scanf("%s", contact1.brith);
			printf("Digite o email: ");
			scanf("%s", contact1.email);

			addContact(&data, &size, contact1);
			printf("Contato adicionado com sucesso.\n");

		} else if (option == 3) {
			printf("Nome de quem deseja encontrar: ");
			char search[sizeof(char) * 40];
			scanf("%s", search);

			int found = 0;
			for (int i = 0; i < size; i++) {
				if (strcmp(data[i].name, search) == 0) {
					printf("Nome: %s\n", data[i].name);
					printf("Número: %s\n", data[i].cellphone);
					printf("Telefone: %s\n", data[i].number);
					printf("Aniversário: %s\n", data[i].brith);
					printf("Email: %s\n\n", data[i].email);
					found = 1;
					break;
				}
			}
			if (!found) {
				printf("Contato não encontrado!\n");
			}
		} else if (option == 4) {
			printf("Nome do contato para editar: ");
			char search[sizeof(char) * 40];
			scanf("%s", search);
			editContact(data, size, search);
		} else if (option == 5) {
			printf("Nome do contato para remover: ");
			char search[sizeof(char) * 40];
			scanf("%s", search);
			removeContact(&data, &size, search);
		}
	} while (option != 6);

	free(data);
	return 0;
}
ro