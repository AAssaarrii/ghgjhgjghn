#pragma once
#include "Pre-Settings.h"
#include "ChannelHeader.h"

namespace TestLab
{
	/// <summary>
	/// Представляет поставщика данных канала.
	/// </summary>
	struct ChannelProvider
	{
	public:
		/// <summary>
		/// Поле для хранения смещения данных от начала файла в байтах.
		/// </summary>
		quint64		DataOffset;
	public:
		/// <summary>
		/// Поле для хранения размера данных в байтах.
		/// </summary>
		quintptr	DataSize;
	private:
		/// <summary>
		/// Поле для хранения формата данных.
		/// </summary>
		quintptr	m_DataFormat;
	public:
		/// <summary>
		/// Поле для хранения коэффициента смещения.
		/// </summary>
		float		BiasFactor;
	public:
		/// <summary>
		/// Поле для хранения масштабного коэффициента.
		/// </summary>
		float		ScaleFactor;
	public:
		/// <summary>
		/// Инициализирует новый экземпляр класса.
		/// </summary>
		ChannelProvider(void) noexcept;
	public:
		/// <summary>
		/// Инициализирует новый экземпляр класса.
		/// </summary>
		/// <param name="dataOffset">
		/// Смещение данных от начала файла в байтах.
		/// </param>
		/// <param name="dataSize">
		/// Размер данных в байтах.
		/// </param>
		/// <param name="dataFormat">
		/// Формата данных.
		/// </param>
		/// <param name="biasFactor">
		/// Коэффициент смещения.
		/// </param>
		/// <param name="scaleFactor">
		/// Масштабный коэффициент.
		/// </param>
		ChannelProvider(quint64 dataOffset, quintptr dataSize,
			ChannelDataFormat dataFormat, float biasFactor, float scaleFactor) noexcept;
	public:
		/// <summary>
		/// Инициализирует новый экземпляр класса.
		/// </summary>
		/// <param name="dataOffset">
		/// Смещение данных от начала файла в байтах.
		/// </param>
		/// <param name="header">
		/// Заголовок канала.
		/// </param>
		ChannelProvider(quint64 dataOffset, const ChannelHeader &header) noexcept;
	public:
		/// <summary>
		/// Возвращает формат данных.
		/// </summary>
		/// <returns>
		/// Формат данных.
		/// </returns>
		inline ChannelDataFormat GetDataFormat(void) const noexcept;
	public:
		/// <summary>
		/// Задаёт формат данных.
		/// </summary>
		/// <param name="dataOffset">
		/// Формат данных.
		/// </param>
		inline void SetDataFormat(ChannelDataFormat dataFormat) noexcept;
	public:
		/// <summary>
		/// Нормализует формат данных.
		/// </summary>
		inline void DataFormatNormalization(void) noexcept;
	public:
		/// <summary>
		/// Извлекает данные канала.
		/// </summary>
		/// <param name="destination">
		/// Массив, в который необходимо поместить данные.
		/// </param>
		/// <param name="source">
		/// Указатель на область памяти, спроецированную из файла.
		/// </param>
		/// <param name="source">
		/// Длина массива данных.
		/// </param>
		void Extraction(qreal *destination, const void *source, quintptr length);
	public:
		/// <summary>
		/// Упаковывает данные канала.
		/// </summary>
		/// <param name="destination">
		/// Указатель на область памяти, спроецированную из файла.
		/// </param>
		/// <param name="source">
		/// Массив, данные из которого необходимо в файл.
		/// </param>
		/// <param name="source">
		/// Длина массива данных.
		/// </param>
		void Packaging(void *destination, const qreal *source, quintptr length);
	};

	inline ChannelDataFormat ChannelProvider::GetDataFormat(void) const noexcept
	{
		return static_cast<ChannelDataFormat>(m_DataFormat);
	}
	
	inline void ChannelProvider::SetDataFormat(ChannelDataFormat dataFormat) noexcept
	{
		m_DataFormat = static_cast<quintptr>(dataFormat);
	}

	inline void ChannelProvider::DataFormatNormalization(void) noexcept
	{
		if (!ChannelHeader::GetItemSize(GetDataFormat()))
		{
			SetDataFormat(ChannelDataFormat::Float32);
		}
	}
}

Q_DECLARE_METATYPE(TestLab::ChannelProvider)

//  Для кодировки этого файла.
