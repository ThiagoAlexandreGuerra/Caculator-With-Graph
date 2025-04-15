import INFO from "./INFO.js";

export default function CallPoint(expr){

  async function init() {
    
  const Module = await MyModule(); 

  try {
    
    const points = Module.cwrap("points", "string", ["string"]);
    const resultado = points(expr);
    const json = JSON.parse(resultado);

    console.log("Tudo certo:", json);
    CallCanvas(json); 
    INFO(json);
    const ContentConsoleAtvGrafic_Animation_ATV=document.querySelector("#ContentConsoleAtvGrafic_Animation");
    ContentConsoleAtvGrafic_Animation_ATV.classList.add("ContentConsoleAtvGrafic_Animation_ATV");

  } catch (err) {
    console.error("❌ Erro na função WebAssembly:", err);
  }
}


init();

}