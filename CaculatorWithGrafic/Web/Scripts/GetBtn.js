import CallPoint from "./lab.js"
const contentNumbers=document.querySelector("#ContentNumber")
const input_e_display=document.querySelector("#P_ContentDiplay")

let numbers_input_for_user=" "
let symbol_operating= true
let decimal_mark = true 

document.addEventListener("keydown",(evento)=>{
    
    const ignoreKeys = [
    "F1", "F2", "F3", "F4", "F5", "F6",
    "F7", "F8", "F9", "F10", "F11", "F12",
     "Escape", "Tab"
  ];

  if (ignoreKeys.includes(evento.key)) {
    console.log(`Tecla ignorada: ${evento.key}`);
    evento.preventDefault(); // opcional: evita comportamento padrão (ex: F1 abre ajuda do navegador)
    return;
  }

    if(evento.key=="Backspace"){
            
            let char_array= numbers_input_for_user.split("")
            
            if(char_array[char_array.length-1]=="."){
                decimal_mark=true
                
                
            }
            
            try {
                const regex = /&\w+;/g;
                
                const matches = numbers_input_for_user.match(regex);
            
                if (matches) {

                    const firstMatchIndex = numbers_input_for_user.indexOf(matches[0]);
                    
                    if (char_array[char_array.length - 1] === ";") {
                        
                        numbers_input_for_user = numbers_input_for_user.slice( 0, firstMatchIndex +1) 
                        input_e_display.innerHTML = numbers_input_for_user;
                    }
                }
            } catch (error) {
                throw new Error("A problem occurred");
            }

            
            try {
                const variable_regex=[

                        {sine:/s\w*n/gi},
                        {cosine:/c\w*s/gi},
                        {log:/l\w*g/gi},
                        {ln:/l\w*n/gi},
                        {inv:/i\w*v/gi},
                        {deg:/d\w*g/ig}
                    ]
                
                for(let i = 0 ; i<variable_regex.length ; ++i){
                    
                    let temporary_regex=Object.values(variable_regex[i])[0]

                    const matches = numbers_input_for_user.match(temporary_regex);
                    
                    if (matches) {
                        
                        const firstMatchIndex = numbers_input_for_user.indexOf(matches[0]);
                        let matches_length=matches.toString().length
                        let matches_string=matches.toString()
                        
                        if (char_array[char_array.length - 1] === (matches_string[matches_length - 1])) {
                            
                            numbers_input_for_user = numbers_input_for_user.slice( 0, firstMatchIndex +1) 
                            input_e_display.innerHTML = numbers_input_for_user;
                        }
                    }
                }

            }catch (error) {
                
                throw new Error("A problem occurred");
            }
                

            numbers_input_for_user= numbers_input_for_user.slice(0,-1)
            input_e_display.innerHTML= numbers_input_for_user

        }else if(evento.key=="." && decimal_mark==true){
            
            numbers_input_for_user+=evento.target.value
            input_e_display.innerHTML=numbers_input_for_user
            decimal_mark=false
            console.log("helo")
        }else if(evento.target.value != undefined && evento.target.value !="." ){

            numbers_input_for_user+=evento.target.value
            input_e_display.innerHTML=numbers_input_for_user
        }
        
        if(evento.key== "="){
        const string_mathematical_operation_desired_by_the_user=input_e_display.innerHTML
        // const result_of_the_operation= eval(string_mathematical_operation_desired_by_the_user)
        CallPoint(string_mathematical_operation_desired_by_the_user);
        input_e_display.innerHTML=result_of_the_operation
        console.log("chamou")

    }
    
    if((evento.key != undefined) && (symbol_operating == true && ( evento.target.value != "=")) ){

        numbers_input_for_user += evento.key
        input_e_display.innerHTML= numbers_input_for_user
        symbol_operating= false
        
        if((evento.target.value == "cos") || (evento.target.value == "sen") || (evento.target.value == "ln") ||
        (evento.target.value =="log") || (evento.target.value == "INV") || (evento.target.value =="deg") ||
        (evento.target.value == "!")  || (evento.target.value == "e")   ){
            decimal_mark=false
        }
    } 

})






contentNumbers.addEventListener("click", (evento)=>{
    
        symbol_operating=true

        if(evento.target.value=="delete"){
            
            let char_array= numbers_input_for_user.split("")
            
            if(char_array[char_array.length-1]=="."){
                decimal_mark=true
                

            }

            try {
                const regex = /&\w+;/g;
            
                const matches = numbers_input_for_user.match(regex);
                
                if (matches) {

                    const firstMatchIndex = numbers_input_for_user.indexOf(matches[0]);
            
                    if (char_array[char_array.length - 1] === ";") {

                        numbers_input_for_user = numbers_input_for_user.slice( 0, firstMatchIndex +1) 
                        input_e_display.innerHTML = numbers_input_for_user;
                    }
                }
            } catch (error) {
                throw new Error("A problem occurred");
            }

            
            try {
                    const variable_regex=[

                        {sine:/s\w*n/gi},
                        {cosine:/c\w*s/gi},
                        {log:/l\w*g/gi},
                        {ln:/l\w*n/gi},
                        {inv:/i\w*v/gi},
                        {deg:/d\w*g/ig}
                    ]
                    
                    for(let i = 0 ; i<variable_regex.length ; ++i){
                        
                    let temporary_regex=Object.values(variable_regex[i])[0]

                    const matches = numbers_input_for_user.match(temporary_regex);
                    
                    if (matches) {
                        
                        const firstMatchIndex = numbers_input_for_user.indexOf(matches[0]);
                        let matches_length=matches.toString().length
                        let matches_string=matches.toString()
                        
                        if (char_array[char_array.length - 1] === (matches_string[matches_length - 1])) {
                            
                            numbers_input_for_user = numbers_input_for_user.slice( 0, firstMatchIndex +1) 
                            input_e_display.innerHTML = numbers_input_for_user;
                        }
                    }
                }

            }catch (error) {

                throw new Error("A problem occurred");
            }
                
            
            numbers_input_for_user= numbers_input_for_user.slice(0,-1)
            input_e_display.innerHTML= numbers_input_for_user

        }else if(evento.target.value=="." && decimal_mark==true){
            
            numbers_input_for_user+=evento.target.value
            input_e_display.innerHTML=numbers_input_for_user
            decimal_mark=false
            console.log("helo")
        }else if(evento.target.value != undefined && evento.target.value !="." ){

            numbers_input_for_user+=evento.target.value
            input_e_display.innerHTML=numbers_input_for_user
        }
        
    
    })
    
const ApagarTudoButton=document.querySelector("#CleanAll")

ApagarTudoButton.addEventListener("click" , ()=>{
    
    decimal_mark=true
    numbers_input_for_user=" "
    input_e_display.innerHTML=numbers_input_for_user
})

const contentSimbolos= document.querySelector("#ContentSing");

contentSimbolos.addEventListener("click",(evento)=>{
    
    console.log("call!!!!!!!!!!!!");
    if(evento.target.value== "="){
        const string_mathematical_operation_desired_by_the_user=input_e_display.innerHTML
        //const result_of_the_operation= eval(string_mathematical_operation_desired_by_the_user)
        CallPoint(string_mathematical_operation_desired_by_the_user);
        input_e_display.innerHTML=result_of_the_operation
        console.log(string_mathematical_operation_desired_by_the_user)

    }

    if((evento.target.value != undefined) && (symbol_operating == true && ( evento.target.value != "=")) ){

        numbers_input_for_user += evento.target.value
        input_e_display.innerHTML= numbers_input_for_user
        symbol_operating= false

        if((evento.target.value == "cos") || (evento.target.value == "sen") || (evento.target.value == "ln") ||
            (evento.target.value =="log") || (evento.target.value == "INV") || (evento.target.value =="deg") ||
            (evento.target.value == "!")  || (evento.target.value == "e")   ){
                decimal_mark=false
            }
    }
})



