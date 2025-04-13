const CallCanvas = (JJson) => {
    const ctx = document.getElementById('grafico').getContext('2d');

    const grafico = new Chart(ctx, {
        type: 'scatter',
        data: {
            datasets: [{
                label: 'Pontos no plano cartesiano',
                data: JJson.data,
                backgroundColor: 'red',
                showLine: true, // Mostra a linha entre os pontos
                borderColor: 'red',
                pointRadius: 2,
                clip: true // Recorta os pontos fora da escala visível
            }]
        },
        options: {
            plugins: {
                legend: {
                    display: true,
                }
            },
            elements: {
                point: {
                    radius: 2
                }
            },
            scales: {
                x: {
                    type: 'linear',
                    position: 'bottom',
                    min: -2,//remember******************************************
                    max: 2,
                    title: {
                        display: true,
                        text: 'Eixo das Abcissas (X)'
                    },
                    grid: {
                        drawOnChartArea: true,
                        color: (ctx) => (ctx.tick.value === 0 ? 'white' : '#ddd'),
                        lineWidth: (ctx) => (ctx.tick.value === 0 ? 2 : 1)
                    }
                },
                y: {
                    type: 'linear',
                    min: -2,
                    max: 2,
                    title: {
                        display: true,
                        text: 'Eixo das Ordenadas (Y)'
                    },
                    grid: {
                        drawOnChartArea: true,
                        color: (ctx) => (ctx.tick.value === 0 ? 'white' : '#ddd'),
                        lineWidth: (ctx) => (ctx.tick.value === 0 ? 2 : 1)
                    }
                }
            }
        }
    });
}
