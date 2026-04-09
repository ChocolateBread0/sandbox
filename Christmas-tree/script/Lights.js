// Lights.js
const delay = ms => new Promise(res => setTimeout(res, ms));

async function showLight(ID) 
{
    //-------------shuffle-------------
    const totaleStelle = ID; 
    const quantitaDaPrendere = Math.trunc(totaleStelle * 0.3);

    let tuttiGliIndici = Array.from({ length: totaleStelle }, (_, i) => i);

    for (let i = tuttiGliIndici.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [tuttiGliIndici[i], tuttiGliIndici[j]] = [tuttiGliIndici[j], tuttiGliIndici[i]];
    }

    const casualiScelti = tuttiGliIndici.slice(0, Math.trunc(totaleStelle * 0.15));
    //-------------shuffle-------------


    while(true) {
        console.log("Eseguo operazione... " + new Date().toLocaleTimeString());

        for (let index = 0; index < casualiScelti.length; index++) {
            // We alternate randomly between Cyan and Magenta
            const isMagenta = Math.random() > 0.5;
            
            if (isMagenta) {
                // Magenta Neon
                document.getElementById(casualiScelti[index]).style.color = getColor(200, 255, 0, 50, 150, 255);
            } else {
                // Cyan Neon
                document.getElementById(casualiScelti[index]).style.color = getColor(0, 50, 200, 255, 200, 255);
            }
        }
    
        await delay(1000);
    }
}
