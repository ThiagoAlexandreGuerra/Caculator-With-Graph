
let position_x= 0
let position_y= 0

window.addEventListener("mousemove" , (evento)=>{

    position_x=evento.clientX
    position_y=evento.clientY

    let rotate= Math.atan2(position_y,position_x)*180/Math.PI

})

const draggable = document.getElementById('ContentAll');
let offsetX = 0, offsetY = 0, isDragging = false;

draggable.addEventListener('mousedown', (e) => {
  isDragging = true;
  offsetX = e.clientX - draggable.offsetLeft;
  offsetY = e.clientY - draggable.offsetTop;
  draggable.style.cursor = 'grabbing';
});

document.addEventListener('mousemove', (e) => {
  if (!isDragging) return;

  const newX = e.clientX - offsetX;
  const newY = e.clientY - offsetY;

  draggable.style.left = `${newX}px`;
  draggable.style.top = `${newY}px`;
});

document.addEventListener('mouseup', () => {
  if (isDragging) {
    isDragging = false;
    draggable.style.cursor = 'grab';
  }
});