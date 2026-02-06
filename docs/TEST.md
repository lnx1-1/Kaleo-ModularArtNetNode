# Abnahme-Test (DMX + Captive Portal)

Diese Checkliste ist kurz und praxisnah. Ziel ist: stabile Ethernet/DMX Funktion, sichere Fallbacks, sauberes Captive Portal.

## 1. Boot ohne Ethernet
- [ ] Gerät ohne Ethernet starten.
- [ ] Nach ~10s erscheint AP `SYNAPSE-LNX-Setup-XXXXXX`.
- [ ] Verbindung möglich, Captive-Portal Seite lädt.
- [ ] AP schaltet sich nach der eingestellten Dauer (Default 180s) aus.

## 2. Boot mit Ethernet
- [ ] Gerät mit Ethernet starten.
- [ ] Kein AP sichtbar.
- [ ] Web-UI über statische IP erreichbar.

## 3. Ethernet Link-Drop
- [ ] Kabel ziehen -> Log zeigt "Disconnected".
- [ ] Kabel rein -> Log zeigt "Connected / Got IP".
- [ ] ArtNet läuft wieder.

## 4. Captive-Portal Config speichern
- [ ] IP, Gateway, Universe ändern.
- [ ] Speichern -> Gerät reinitialisiert, erreichbar unter neuer IP.

## 5. Input-Mode Umschalten
- [ ] ArtNet -> DMX: ArtNet ignoriert, DMX verarbeitet.
- [ ] DMX -> ArtNet: DMX deaktiviert, ArtNet verarbeitet.
- [ ] Keine Fehlermeldungen im Log.

## 6. DMX Signalfluss
- [ ] DMX rein -> Fixtures reagieren.
- [ ] DMX-Statusseite zeigt Werte.

## 7. DMX Fallback (Blackout)
- [ ] DMX Signal trennen.
- [ ] Nach ~1s Blackout (bewegende Elemente stoppen).
- [ ] DMX Signal wieder an -> normaler Betrieb.

## 8. Performance (ohne Web-UI)
- [ ] Web-UI nicht geöffnet -> keine sichtbaren Aussetzer.

Optional:
- [ ] /dmx Seite geöffnet -> weiterhin stabil.
