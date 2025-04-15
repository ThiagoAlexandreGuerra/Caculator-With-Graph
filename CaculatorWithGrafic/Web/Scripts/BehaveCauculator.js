
const BTN_GO = document.querySelector("#GO");
const Content_Canvas = document.querySelector("#ContentCanvas");

const BTN_info= document.querySelector("#buttonHandleGraph_info")
const Content_HandleGraph=document.querySelector("#canvas_canvas");

const ContentConsoleAtvGrafic_Animation=document.querySelector("#ContentConsoleAtvGrafic_Animation");

ContentConsoleAtvGrafic_Animation.addEventListener("click", ()=>{
    Content_Canvas.classList.toggle("GO_Left");
})

// BTN_GO.addEventListener("click", () => {
//     Content_Canvas.classList.toggle("GO_Left");
//     console.log("go!!")
// });

let i=0;
BTN_info.addEventListener("click" , ()=>{
    if(i==90){i=0;}else{i+=90;}
    Content_HandleGraph.style.transform=` rotateY(${i}deg)`;

})

