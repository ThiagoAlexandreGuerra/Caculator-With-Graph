# 📱 Calculadora com Gráfico | Graphing Calculator App

## 🇧🇷 Português

**Calculadora com Gráfico** é um aplicativo que busca facilitar os estudos em matemática ao unir o poder de uma calculadora tradicional com a interatividade gráfica de ferramentas como o GeoGebra. O objetivo principal é proporcionar uma experiência fluida, intuitiva e eficiente, onde o usuário pode visualizar os resultados de suas expressões em um display dinâmico e responsivo.

### ✨ Principais Funcionalidades

- Interface interativa para resolução de expressões matemáticas
- Geração de gráficos em tempo real
- Processamento de expressões via WebAssembly para alta performance
- Backend em C++ com TADs organizados e estruturados

### 🧩 Estrutura do Projeto

O projeto é dividido em três camadas principais:

- **Frontend (HTML + CSS + JS)**: Recebe a string de entrada do usuário, filtra e envia para o WebAssembly.
- **WebAssembly**: Responsável por intermediar a comunicação e garantir performance.
- **Módulos C++ (TADs)**: Implementam a lógica matemática e retornam os dados processados.

### 🧠 Lógica Interna (C++)

- `FindNumber.cpp`: Responsável por identificar os intervalos de números (ex: `+ou-...-ou+`). Utiliza a biblioteca externa **muparser** para interpretar e calcular expressões.
- `FormatFunction.cpp`: Atribui os valores corretos para cada tipo de `x`.
- `GerPoints.cpp`: Gera os pontos da função formatada.
- `OutputTad.cpp`: Converte os dados gerados em uma string com estrutura **JSON** para fácil interpretação no JavaScript.

Essa estrutura permite escalabilidade, permitindo adicionar novos dados apenas concatenando strings, sem necessidade de novos métodos de exportação.

### 🚧 Status do Projeto

> **Em desenvolvimento** (Estimativa de conclusão: ~2 semanas)

Pendências:
- Reconhecimento de novas funções matemáticas
- Refinamento do design
- Correção de bugs
- Otimizações de performance

---

## 🇺🇸 English

**Graphing Calculator** is an app designed to make studying math easier by combining the power of a traditional calculator with the interactivity of tools like GeoGebra. The main goal is to offer a fluid, intuitive, and efficient experience where users can visualize their math expressions dynamically and clearly.

### ✨ Key Features

- Interactive interface for solving math expressions
- Real-time graph rendering
- WebAssembly processing for high performance
- C++ backend with structured ADTs (Abstract Data Types)

### 🧩 Project Structure

The project is split into three main layers:

- **Frontend (HTML + CSS + JS)**: Captures and filters user input, sending it to WebAssembly.
- **WebAssembly**: Bridges the frontend with C++ logic, ensuring speed and efficiency.
- **C++ Modules (TADs)**: Handle the mathematical logic and return processed data.

### 🧠 Internal Logic (C++)

- `FindNumber.cpp`: Locates number intervals (e.g., `+or-...-or+`) and uses the external **muparser** library for expression evaluation.
- `FormatFunction.cpp`: Assigns appropriate values to each `x` instance.
- `GerPoints.cpp`: Generates all necessary points from the formatted function.
- `OutputTad.cpp`: Converts all generated data into a **JSON-formatted string**, making it easy to parse in JavaScript.

The JSON approach allows scalability, where new data can simply be appended to the string without creating new export methods.

### 🚧 Project Status

> **In development** (Estimated completion: ~2 weeks)

To-do:
- Add support for new mathematical functions
- Refine the visual design
- Fix bugs
- Improve performance and responsiveness

---

### 📌 Tecnologias Utilizadas / Technologies Used

- C++ (Lógica matemática / Math logic)
- WebAssembly (Integração com frontend / Frontend integration)
- JavaScript (Manipulação e exibição gráfica / Logic & rendering)
- HTML5 + CSS3 (Interface)
- [muparser](https://beltoforion.de/en/muparser/) (Parser de expressões matemáticas)

---

### 📈 Autor / Author

**Thiago Alexandre Guerra**  
Estudante de Ciência da Computação – Universidade Federal de Juiz de Fora (MG)  
Desenvolvedor com interesse em design, matemática, performance e interatividade.
