//**************************************************************//
//  FSManager.cpp                                               //
//  Implementação da classe FSManager                           //
//  Autor: Cahu Silva                                           //
//  Data: 2024                                                  //
//**************************************************************//

#include "FSManager.h"

FSManager::FSManager() {
    // Inicializa o sistema de arquivos ao criar o objeto
    openFS(true);
}

FSManager::~FSManager() {
    // Fecha o sistema de arquivos ao destruir o objeto
    closeFS();
}

bool FSManager::formatFS() {
    Serial.println("Formatando o sistema de arquivos...");
    if (LittleFS.format()) {
        Serial.println("Sistema de arquivos formatado com sucesso.");
        return true;
    } else {
        Serial.println("Falha ao formatar o sistema de arquivos.");
        return false;
    }
}

bool FSManager::openFS(bool formatOnFail) {
    Serial.println("Montando o sistema de arquivos...");
    if (!LittleFS.begin(formatOnFail)) {
        Serial.println("Falha ao montar o sistema de arquivos.");
        return false;
    }
    Serial.println("Sistema de arquivos montado com sucesso.");
    return true;
}

void FSManager::closeFS() {
    LittleFS.end();
    Serial.println("Sistema de arquivos desmontado.");
}

bool FSManager::createFile(const char* fileName) {
    if (LittleFS.exists(fileName)) {
        Serial.printf("O arquivo '%s' já existe.\n", fileName);
        return false;
    } else {
        Serial.printf("Criando o arquivo '%s'...\n", fileName);
        File file = LittleFS.open(fileName, "w");
        if (!file) {
            Serial.println("Falha ao criar o arquivo.");
            return false;
        } else {
            Serial.println("Arquivo criado com sucesso.");
            file.close();
            return true;
        }
    }
}

bool FSManager::deleteFile(const char* fileName) {
    Serial.printf("Excluindo o arquivo '%s'...\n", fileName);
    if (LittleFS.remove(fileName)) {
        Serial.println("Arquivo excluído com sucesso.");
        return true;
    } else {
        Serial.println("Falha ao excluir o arquivo.");
        return false;
    }
}

bool FSManager::writeFile(const char* fileName, const String& message) {
    Serial.printf("Escrevendo no arquivo '%s'...\n", fileName);
    File file = LittleFS.open(fileName, "a");
    if (!file) {
        Serial.println("Falha ao abrir o arquivo para escrita.");
        return false;
    } else {
        if (file.println(message)) {
            Serial.println("Escrita realizada com sucesso.");
            file.close();
            return true;
        } else {
            Serial.println("Falha na escrita.");
            file.close();
            return false;
        }
    }
}

bool FSManager::readFile(const char* fileName) {
    Serial.printf("Lendo o arquivo '%s'...\n", fileName);
    File file = LittleFS.open(fileName, "r");
    if (!file) {
        Serial.println("Falha ao abrir o arquivo para leitura.");
        return false;
    } else {
        while (file.available()) {
            String line = file.readStringUntil('\n');
            Serial.println(line);
        }
        file.close();
        return true;
    }
}

void FSManager::listFSInfo() {
    Serial.println("Informações do Sistema de Arquivos:");
    Serial.printf("Espaço total: %u bytes\n", LittleFS.totalBytes());
    Serial.printf("Espaço usado: %u bytes\n", LittleFS.usedBytes());
}
