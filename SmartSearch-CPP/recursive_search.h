#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <filesystem> //per cercare file
#include <vector> //per creare vettori
#include <cstddef>         // std::size_t


using namespace std;
namespace fs = std::filesystem;

class recursive_search
{
private:
    DWORD Nfile = 0;
    DWORD Nfolders = 0;
    DWORD NTrovati = 0;
    // Vettore per memorizzare le righe del file e delle cartelle    
    vector<std::string> files, folders;
    string percorsoFile = "";    //percorsoFile = indirizzo file di destinazione

    void ricorsione(string fpath)
    {
        vector<string> Subcartelle;
        try
        {
            for (const auto& entry : fs::directory_iterator(fpath))
            {
                if (fs::is_directory(entry))
                {
                    Subcartelle.push_back(fs::absolute(entry.path()).string());  

                    if(folders.size() != 0)
                        confronta(entry,true);//se il vettore è vuoto non devo cercare nessuna cartella

                    Nfolders++;
                }
                else if (fs::is_regular_file(entry)) //se è un file entro qui
                {           
                    if (files.size() != 0) {
                        confronta(entry, false); //se il vettore è vuoto non devo cercare nessun file
                    }                    
                    Nfile++;
                }
            }
        }
        catch (const std::exception&) {}

        if (Subcartelle.size() == 0)
            return;
        else
            ricorsione(Subcartelle.at(0));

        try
        {
            for (;;)
            {
                Subcartelle.erase(Subcartelle.begin(), Subcartelle.begin() + 1); //elimino il primo elemento dell'array pochè gia stato chiamato
                ricorsione(Subcartelle.at(0));
            }
        }
        catch (const std::exception&) {}
    }
    
    void confronta(const fs::directory_entry percorso, bool isDir)
    {
        //converto directory_entry in stringa
        string percoprol = percorso.path().string();
        //separo il percorso prendendo solo il nome della cartella o del file
        string File_cartell = percoprol.substr(percoprol.find_last_of("\\") + 1, percoprol.length());

        //scrivo il percorso sul file. Lo apro.
        ofstream outputFile(percorsoFile, ios::app);
        
        if (outputFile.is_open())
        {
            if (isDir) //ho una cartella
            {
                //prendo la cartella trovata e la confronto con le cartelle nell'array
                for (int i = 0; i < folders.size(); i++)
                {
                    if (File_cartell.find(folders[i]) != std::string::npos)
                    {
                        NTrovati++;
                        outputFile << "<div style=\"margin - bottom: 8px; \">" 
                            << "<span style=\"font - weight: bold; color: #2b2b2b; \">" << NTrovati << ") " << "</span>" 
                            <<"<span style=\"font - weight: bold; color: #1e88e5; \">[Cartella]</span>" 
                            <<"<span style=\"font - family: Consolas, monospace; color: #555; \">"<<
                            "<a href=\"file:///"<< percoprol << "\" style=\"color: inherit; text-decoration: none;\">" << percoprol << "</a></span>"
                            << "</div>" << endl;
                    }
                }
            }
            else //ho un file o estensione
            {
                //prendo la cartella trovata e la confronto con le cartelle nell'array
                for (int i = 0; i < files.size(); i++)
                {
                    if (File_cartell.find(files[i]) != std::string::npos)
                    {
                        NTrovati++;
                        outputFile << "<div style=\"margin - bottom: 8px; \">"
                            << "<span style=\"font - weight: bold; color: #2b2b2b; \">" << NTrovati << ") " << "</span>"
                            << "<span style=\"font - weight: bold; color: #1e88e5; \">[File]</span>"
                            << "<span style=\"font - family: Consolas, monospace; color: #555; \">" <<
                            "<a href=\"file:///" << percoprol << "\" style=\"color: inherit; text-decoration: none;\">" << percoprol << "</a></span>"
                            << "</div>" << endl;
                    }
                }
            }
        }
        else{}
        outputFile.close();
    }

public: 
    void main(string &Mpath, vector<std::string> &Mfiles, vector<std::string> &Mfolders, string& MpercorsoFile)
    {
        //qui imposto le variabili iniziali
        files = Mfiles;
        folders = Mfolders;
        percorsoFile = MpercorsoFile;

        ricorsione(Mpath);
    }

    std::tuple<DWORD, DWORD, DWORD> getCounts() {
        return { Nfile, Nfolders, NTrovati };
    }  
};