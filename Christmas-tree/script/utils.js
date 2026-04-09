function getColor(rMin, rMax, gMin, gMax, bMin, bMax) {
    const r = Math.floor(Math.random() * (rMax - rMin) + rMin);
    const g = Math.floor(Math.random() * (gMax - gMin) + gMin);
    const b = Math.floor(Math.random() * (bMax - bMin) + bMin);
    return `rgb(${r}, ${g}, ${b})`;
}