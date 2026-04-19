#!/bin/bash

# Limpar o terminal
clear

# Limpar os arquivos de compilação anteriores
make clean
if [ $? -ne 0 ]; then
    echo "Erro ao executar 'make clean'. Abortando."
    exit 1
fi

# Compilar o projeto com 2 núcleos, caso 'make clean' tenha sido bem-sucedido
make -j2
if [ $? -ne 0 ]; then
    echo "Erro ao executar 'make'. Abortando."
    exit 1
fi

# Executar o aplicativo
./ApsAnalise
if [ $? -ne 0 ]; then
    echo "Erro ao executar './ApsAnalise'."
    exit 1
fi

echo "Compilação e execução bem-sucedidas!"