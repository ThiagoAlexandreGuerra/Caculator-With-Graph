export default function CallPoint(expr){

  async function init() {
    // MyModule está definido globalmente pelo arquivo externo MyFunction.js
  const Module = await MyModule(); 

  try {
    // cwrap cria uma função JS que chama a função C++ "points"
    const points = Module.cwrap("points", "string", ["string"]);
    const resultado = points(expr);
    const json = JSON.parse(resultado);

    console.log("Tudo certo:", json);
    CallCanvas(json); // Essa função deve estar definida globalmente também
  } catch (err) {
    console.error("❌ Erro na função WebAssembly:", err);
  }
}

// Inicializa o módulo
init();

}