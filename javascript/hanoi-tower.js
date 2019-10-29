function hanoiTower(disc, src, aux, dist) {
	if (disc > 0) {
		hanoiTower(disc - 1, src, dist, aux)
		console.log(`Move disc ${disc} from ${src} to ${dist}`);
		hanoiTower(disc - 1, aux, src, dist);
	}
}

