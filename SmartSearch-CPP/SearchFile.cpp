#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <filesystem> //per cercare file
#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include "recursive_search.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    // Salva il tempo iniziale
    auto inizio = std::chrono::high_resolution_clock::now();

    string path = "C:\\";
    DWORD Nfile = 0, Nfolder = 0, FilesTrovati = 0;
    string Files_to_search, estensione, percorsoFile = "risultati.html";
    bool add_to_file = false, add_to_fold = false;

    // Vettore per memorizzare le righe del file    
    vector<std::string> files, folders;

    recursive_search search;

    // Apri il file in lettura
    std::ifstream documenti("exstensions.txt");

    // Verifica se il file è stato aperto correttamente
    if (documenti.is_open())
    {
        //leggi il file riga per riga
        while (std::getline(documenti, Files_to_search))
        {
            if (Files_to_search != "" && Files_to_search.find("!--") == std::string::npos
                && Files_to_search != " ")
            {
                //cerco i "#" questo mi dice se ho file o cartelle
                if (Files_to_search.find("#") != std::string::npos || add_to_file ||add_to_fold)
                {
                    //questa riga mi dice cosa cercare, fi,le, cartelle entrambi.
                    if ((Files_to_search.find("File") != std::string::npos || add_to_file)
                        && (Files_to_search.find("Cartelle") == std::string::npos || add_to_fold))
                    {
                        add_to_file = true;
                        //qui ci saranno i file
                        files.push_back(Files_to_search);
                    }
                    else
                    {
                        add_to_file = false;
                        add_to_fold = true;
                        //qui ci saranno le cartelle, 
                        folders.push_back(Files_to_search);
                    }
                }
            }
            
        }
        
        //elimino il primo elemento che contiene la categoria "#file" o "#cartelle" 
        files.erase(files.begin());
        folders.erase(folders.begin());

        ofstream outputFile(percorsoFile, ios::app); //file output

        if (outputFile.is_open()) {
            outputFile << "<!DOCTYPE html>" << endl<< "<html><head><title>Risultati</title></head><body>"<<endl;               

            search.main(path, files, folders, percorsoFile);

            auto [Nfile, Nfolder, FilesTrovati] = search.getCounts();

            if (FilesTrovati == 0)
            {
                outputFile << "<div style=\"font - family: Consolas, monospace; color: #777; font - style: italic; margin - top: 15px; \">" <<
                    "Nessun file o cartella trovata corrisponde ai termini cercati."<<
                    "</div>" << endl;
            }

            // Salva il tempo finale
            auto fine = std::chrono::high_resolution_clock::now();

            // Calcola la durata in secondi (con decimali)
            std::chrono::duration<double> durata = fine - inizio;

            outputFile << "<div style=\"text-align: center; margin-top: 30px; font-family: 'Arial', sans-serif; color: #333;\">" <<
                "<h2 style=\"margin - bottom: 5px; \">Analisi completata</h2>" <<
                "<p style=\"font - size: 16px; color: #333; margin : 0; \">" <<
                "&#128196; <strong style=\"color: #2b2b2b; \">File trovati:</strong> " << Nfile << "<br>" <<
                "&#128193; <strong style=\"color: #2b2b2b; \">Cartelle esplorate:</strong> " << Nfolder << "<br>" <<
                "&#8987; <strong style=\"color: #2b2b2b; \">Tempo impiegato:</strong> " << durata.count() << " secondi" <<
                "</p>" <<
                "</div>" << "<br>" << "<br>"<<endl;

            outputFile << "<div style=\"text - align: center; font - family: 'Segoe UI', Roboto, Arial, sans - serif; font - size: 14px; color: #888; margin - top: 40px; \">" <<
                "<p> &#128206; <strong>Versione 2.5</strong>  Generato il 09/05/2025 </p>" <<
                " </div>"<<endl;

            outputFile << "</body></html>";

            outputFile.close();
        }
        else {
            std::cerr << "Impossibile aprire il file percorso_trovato.txt" << std::endl;            
        }        
    } 
    else
    {
        std::cerr << "file non trovato" << std::endl;
    }
    documenti.close();

    string aprilo = "start " + percorsoFile;
    system(aprilo.c_str());  // apre log.html con il browser predefinito
}