//**************************************************************//
//  FSManager.h                                                 //
//  Biblioteca Arduino para Gerenciamento de Sistema de Arquivos//
//  Autor: Cahu Silva                                           //
//  Data: 2024                                                  //
//**************************************************************//

#ifndef FSMANAGER_H
#define FSMANAGER_H

#include <Arduino.h>
#include <FS.h>
#include <LittleFS.h>

class FSManager {
public:
    /**
     * @brief Construtor da classe FSManager.
     */
    FSManager();

    /**
     * @brief Destrutor da classe FSManager. Fecha o sistema de arquivos.
     */
    ~FSManager();

    /**
     * @brief Formata o sistema de arquivos.
     * @return true se bem-sucedido, false caso contrário.
     */
    bool formatFS();

    /**
     * @brief Monta o sistema de arquivos.
     * @param formatOnFail Se true, formata o sistema de arquivos se a montagem falhar.
     * @return true se bem-sucedido, false caso contrário.
     */
    bool openFS(bool formatOnFail = true);

    /**
     * @brief Desmonta o sistema de arquivos.
     */
    void closeFS();

    /**
     * @brief Cria um novo arquivo.
     * @param fileName O nome do arquivo a ser criado.
     * @return true se bem-sucedido, false caso contrário.
     */
    bool createFile(const char* fileName);

    /**
     * @brief Exclui um arquivo.
     * @param fileName O nome do arquivo a ser excluído.
     * @return true se bem-sucedido, false caso contrário.
     */
    bool deleteFile(const char* fileName);

    /**
     * @brief Escreve uma mensagem em um arquivo.
     * @param fileName O nome do arquivo.
     * @param message A mensagem a ser escrita.
     * @return true se bem-sucedido, false caso contrário.
     */
    bool writeFile(const char* fileName, const String& message);

    /**
     * @brief Lê e imprime o conteúdo de um arquivo.
     * @param fileName O nome do arquivo a ser lido.
     * @return true se bem-sucedido, false caso contrário.
     */
    bool readFile(const char* fileName);

    /**
     * @brief Imprime informações do sistema de arquivos.
     */
    void listFSInfo();

private:
    // Membros privados podem ser adicionados futuramente se necessário
};

#endif // FSMANAGER_H
