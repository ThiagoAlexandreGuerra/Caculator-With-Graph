const TEXT=document.querySelector("#TEXT");

function createElement(tag, attributes = {}, children = []) {
    console.log("tag: ", tag);
    console.log("attributes: ", attributes);
    console.log("children: ", children);
    const element = document.createElement(tag);
    console.log("call createElement!!!");
    for (const attr in attributes) {
      if (attr === "style") {
        Object.assign(element.style, attributes[attr]); 
      } else if (attr.startsWith("on") && typeof attributes[attr] === "function") {
        element.addEventListener(attr.slice(2), attributes[attr]); 
      } else {
        element.setAttribute(attr, attributes[attr]);
      }
    }
  

    children.forEach(child => {
      if (typeof child === "string") {
        element.appendChild(document.createTextNode(child));
      } else {
        element.appendChild(child);
      }
    });
    
    console.log("Element created" , element)
    return element;
  }
  
export default function INFO(JJSON){
    console.log("call INFO!!!!!!!!!!");
    console.log(JJSON.TYPE[0].T)
    if(JJSON.TYPE[0].T==1){
        console.log("pass if!!!!");
        const FirstRoot= createElement("p" , {
            id:"root1", 
            class:"roots_Class",

        },[JJSON.FindFirstRoot[0].if?`\tSua raiz é ${JJSON.Root[0].x} `:"\tA sua função não possui raiz real !!"] );

        const slope=createElement("p", {
            id:"slope",
            class:"slope_Class",

        },[`    Seu coeficiente angular é ${JJSON.Slope[0].a} `] );
 
        const ConstanteTerm=createElement("p",{
            id:"ConstanteTerm",
            class:"ConstanteTerm_Class",
        },[JJSON.FindConstanteTerm[0].if?`\tSeu termo constante é ${JJSON.FindConstanteTerm[0].c}`:"\tSua Função não possui um termo constante!!"])

        TEXT.appendChild(FirstRoot );
        TEXT.appendChild(slope );
        TEXT.appendChild(ConstanteTerm );
    }
    
}  