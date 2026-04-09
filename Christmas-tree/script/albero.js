
function generaAlbero() {
    const m = 51; // numero di righe
    const container = document.getElementById('tree-container');
    let htmlContent = "";
    let ID_luce = 0;
    // Creazione Chioma
    for (let i = 0; i < m; i++) {
        let k = 2 * i + 1;
        let riga = "";
        
        // Spazi iniziali per centrare
        let spazi = " ".repeat(m - i);
        
        // Generazione stelline colorate
        for (let j = 0; j < k; j++) {
            let coloreVerde = getColor(30, 50, 45, 65, 60, 80);
            riga += `<span class="luce" id="${ID_luce}" style="color: ${coloreVerde}">*</span>`;
            ID_luce = ID_luce+1
        }
        
        htmlContent += `<p>${spazi}${riga}</p>`;        
    }

    // Creazione Tronco
    const larghTronco = Math.floor(m / 4);
    const kTronco = 2 * larghTronco + 1;
    const nSpaziTronco = m - larghTronco;

    for (let i = 0; i < larghTronco; i++) {
        let spazi = " ".repeat(nSpaziTronco);
        let rigaTronco = "";
        
        for (let j = 0; j < kTronco; j++) {
            let coloreMarrone = getColor(60, 90, 40, 60, 20, 40);
            rigaTronco += `<span style="color: ${coloreMarrone}">*</span>`;
        }
        
        htmlContent += `<p>${spazi}${rigaTronco}</p>`;
    }

    // Inseriamo tutto l'HTML generato nel contenitore
    container.innerHTML = htmlContent;
    showLight(ID_luce)
}

// Avvia la funzione al caricamento della pagina
window.onload = generaAlbero;