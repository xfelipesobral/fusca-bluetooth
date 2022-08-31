import { useState, useEffect  } from 'react'
import { StyleSheet, Text, View, SafeAreaView } from 'react-native'
import { StatusBar } from 'expo-status-bar'

import LottieView from 'lottie-react-native'

import { KorolJoystick as Joystick } from 'korol-joystick'

import Cabecalho from './modules/cabecalho'
import Botoes from './modules/botoes'

import aniVelocimetro from './assets/animations/velocimetro.json'

export default function App() {
	const [bluetoothStatus, setBluetoothStatus] = useState(false)

	useEffect(() => {
		setTimeout(() => {
			setBluetoothStatus(true)
		}, 5000)
	}, [])

	return (
		<SafeAreaView style={estilos.container}>
			<Cabecalho bluetoothStatus={bluetoothStatus} />

			<Botoes />

			<View style={estilos.joystick}>
				<Joystick color='#000000' radius={75} onMove={(data) => console.log(data)} />
				<LottieView
                    style={{
                        height: 150,
						width: 200,
						position: 'absolute',
						top: -5,
						zIndex: -1
                    }}
                    source={aniVelocimetro}
					autoPlay
					loop
                    resizeMode='contain'
                />

			</View>

			<StatusBar style='dark' />
		</SafeAreaView>
	);
}

const estilos = StyleSheet.create({
	container: {
		flex: 1,
		backgroundColor: '#f7f7f7',
	},
	joystick: {
		paddingVertical: 20,
		alignItems: 'center',
		justifyContent: 'center',
		flexDirection: 'row'
	}
})
