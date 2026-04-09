// Lights.js
const delay = ms => new Promise(res => setTimeout(res, ms));

// Rimosso "export"
async function showLight(ID) 
{
    //-------------shuffle-------------
    //prendo un array con tutti gli ID, lo mescolo e prendo solo il 30%
    const totaleStelle = ID; // Il numero totale di "*"
    const quantitaDaPrendere = Math.trunc(totaleStelle * 0.3);


    //-------------shuffle VERO-------------
    let tuttiGliIndici = Array.from({ length: totaleStelle }, (_, i) => i);

    for (let i = tuttiGliIndici.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [tuttiGliIndici[i], tuttiGliIndici[j]] = [tuttiGliIndici[j], tuttiGliIndici[i]];
    }

    const casualiScelti = tuttiGliIndici.slice(0, Math.trunc(totaleStelle * 0.15));
    //-------------shuffle VERO-------------


    while(true) {
        console.log("Eseguo operazione... " + new Date().toLocaleTimeString());

        for (let index = 0; index < casualiScelti.length; index++) {
            // Alterniamo tra Ciano e Magenta in modo casuale
            const isMagenta = Math.random() > 0.5;
            
            if (isMagenta) {
                // Magenta Neon
                document.getElementById(casualiScelti[index]).style.color = getColor(200, 255, 0, 50, 150, 255);
            } else {
                // Ciano Neon
                document.getElementById(casualiScelti[index]).style.color = getColor(0, 50, 200, 255, 200, 255);
            }
        }
    
        await delay(1000);
    }
}