const CallCanvas = (JJson) => {
    const ctx = document.getElementById('grafico').getContext('2d');

    const grafico = new Chart(ctx, {
        type: 'line',
        data: {
            datasets: [{
                label: 'Pontos no plano cartesiano',
                data: JJson.data,
                backgroundColor: 'red',
                showLine: true, // Mostra a linha entre os pontos
                borderColor: 'red',
                pointRadius: 1,
                clip: true ,// Recorta os pontos fora da escala visível
                tension: 0.5
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
                    min: -10,//remember******************************************
                    max: 10,
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
                    min: -10,
                    max: 10,
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
