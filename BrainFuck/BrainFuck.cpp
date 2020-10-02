// BrainFuck.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

#define RIGHT 0
#define LEFT 1
#define PLUS 2
#define MINUS 3
#define OUT 4
#define IN 5
#define START 6
#define END 7


void BrainFuck();


int main()
{
    //std::cout << "Hello World!\n";
    BrainFuck();
    return 0;
}

void BrainFuck() {
    int vettore[10000] = {0};
    int pos = 0;
    map<char, int> lookUpTable;
    lookUpTable['<'] = LEFT;
    lookUpTable['>'] = RIGHT;
    lookUpTable['+'] = PLUS;
    lookUpTable['-'] = MINUS;
    lookUpTable['.'] = OUT;
    lookUpTable[','] = IN;
    lookUpTable['['] = START;
    lookUpTable[']'] = END;

    string commands;
    cin >> commands;
    for (int i = 0; i < commands.size(); i++) {
        int command = commands[i];
        switch (lookUpTable[command])
        {
        case LEFT:
            --pos;
            break;
        case RIGHT:
            ++pos;
            break;
        case PLUS:
            vettore[pos]++;
            break;
        case MINUS:
            vettore[pos]--;
            break;
        case OUT:
            cout << (char)vettore[pos] << endl;
            break;
        case IN:
            cin >> vettore[pos];
            break;
        case START:
            if (vettore[pos] == 0) {
                int bNum = 0;
                for (int j = i; j < commands.size(); j++) {
                    switch (lookUpTable[commands[j]])
                    {
                    case START:
                        bNum++;
                        break;
                    case END:
                        bNum--;
                        break;
                    }
                    if (bNum == 0) {
                        i = j;
                        break;
                    }
                }
            }
            break;
        case END:
            if (vettore[pos] != 0) {
                int bNum = 0;
                for (int j = i; j >= 0; j--) {
                    switch (lookUpTable[commands[j]])
                    {
                    case START:
                        bNum++;
                        break;
                    case END:
                        bNum--;
                        break;
                    }
                    if (bNum == 0) {
                        i = j;
                        break;
                    }
                }
            }
            break;
        }

        //string stop;
        //cin >> stop;
        //cout << (char)command << " " << pos << ":" << vettore[pos] << endl;
    }
}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
